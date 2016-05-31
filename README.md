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
## Loading the database with random records
* Key: A monotonically increasing integer, starting at 0
* Value: An arbitrary UUID
```
$ loaddb -n <num recs>
```

# Verifying
Assuming you've installed 1000000 records via loaddb:
```
$ aql
aql> select * from test.personas where pk=999999
+----------------------------------------+
| persona                                |
+----------------------------------------+
| "b1c8254a-9f6a-4f69-8832-b2d98ccbf397" |
+----------------------------------------+
1 row in set (0.000 secs)
