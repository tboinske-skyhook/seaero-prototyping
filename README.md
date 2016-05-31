# seaero-prototyping
Sandbox for testing Seastar and Aerospike platforms

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
