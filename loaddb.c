#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <uuid/uuid.h>

#include <aerospike/aerospike.h>
#include <aerospike/aerospike_key.h>
#include <aerospike/as_error.h>
#include <aerospike/as_record.h>
#include <aerospike/as_status.h>

int main(int argc, char** argv)
{
    int numRecs = 0;
    int c = 0;

    //opterr = 0;

    while ((c = getopt (argc, argv, "n:")) != -1)
    {
        switch (c)
        {
            case 'n':
                numRecs = atoi(optarg);
                break;

            default:
                break;
        }
    }

    if (numRecs == 0)
    {
        printf("usage: loaddb -n <num-recs>\n");
        return 1;
    }

    printf("loading n=%d random records into DB...\n", numRecs);

    as_config config;
    as_config_init(&config);

    //config.hosts[0] = { .addr = "127.0.0.1", .port = 3000 };
    config.hosts[0].addr = "127.0.0.1";
    config.hosts[0].port = 3000;

    aerospike as;
    aerospike_init(&as, &config);

    as_error err;
    aerospike_connect(&as, &err);

    int i = 0;

    for (i = 0; i < numRecs; i++)
    {
        as_key key;
        as_key_init_int64(&key, "test", "personas", i);

        // Create a UUID as a kind of stand in for persona data.
        uuid_t uuid;
        uuid_generate(uuid);

        char ch[37];
        uuid_unparse(uuid, ch);

        as_record rec;
        as_record_init(&rec, 1);
        as_record_set_str(&rec, "persona", ch);

        if (aerospike_key_put(&as, &err, NULL, &key, &rec) != AEROSPIKE_OK)
        {
            printf("error(%d) %s at [%s:%d]", err.code, err.message, err.file, err.line);
        }

        as_record_destroy(&rec);
    }

    aerospike_close(&as, &err); 
    aerospike_destroy(&as);
}
