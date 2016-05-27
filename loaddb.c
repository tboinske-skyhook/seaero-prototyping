#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <aerospike/aerospike.h>
#include <aerospike/aerospike_key.h>
#include <aerospike/as_error.h>
#include <aerospike/as_record.h>
#include <aerospike/as_status.h>

int main(int argc, char** argv)
{
    int numRecs = 0;
    int c = 0;

    opterr = 0;

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
    return 0;

    as_error err;
    as_config config;
    as_config_init(&config);

    //config.hosts[0] = { .addr = "127.0.0.1", .port = 3000 };
    config.hosts[0].addr = "127.0.0.1";
    config.hosts[0].port = 3000;

    aerospike as;
    aerospike_init(&as, &config);

    aerospike_connect(&as, &err);

    as_key key;
    as_key_init(&key, "test", "silly_set", "test_key");

    as_record rec;
    as_record_inita(&rec, 2);
    as_record_set_int64(&rec, "test-bin-1", 1234);
    as_record_set_str(&rec, "test-bin-2", "test-bin-2-data");

    aerospike_key_put(&as, &err, NULL, &key, &rec);

    aerospike_close(&as, &err); 
    aerospike_destroy(&as);
}
