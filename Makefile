loaddb: loaddb.c
	#gcc -std=c11 -g $< -o $@ /usr/lib/libaerospike.a -lssl -lcrypto -lpthread -lrt -ldl -lm -lz -luuid
	gcc $< -o $@ /usr/lib/libaerospike.a -lssl -lcrypto -lpthread -lrt -ldl -lm -lz -luuid
