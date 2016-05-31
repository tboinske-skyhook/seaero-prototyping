# seaero-prototyping
Sandbox for testing Seastar and Aerospike platforms

# Downloads
## Aerospike 
### Community Server Edition
http://www.aerospike.com/download/server/3.8.2.3/
### C Development Client
http://www.aerospike.com/download/client/c/4.0.4/

# Building
```
$ make
```

# Running
```
$ loaddb -n <num recs>
```

# Verifying
This step assumes you've installed the Aerospike tools via
www.aerospike.com
```
$ aql
aql> select * from test.personas where pk=999999
+----------------------------------------+
| persona                                |
+----------------------------------------+
| "b1c8254a-9f6a-4f69-8832-b2d98ccbf397" |
+----------------------------------------+
1 row in set (0.000 secs)
