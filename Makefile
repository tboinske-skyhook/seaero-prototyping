loaddb: loaddb.c
	gcc $< -o $@ /usr/lib/libaerospike.a -lssl -lcrypto -lpthread -lrt -ldl -lm -lz
