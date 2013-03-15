Skelton of Service in Jubatus Framework
=======================================

This is an implementation of a simple key-value store that uses Jubatus framework.

Requirements
------------

+ Jubatus 0.4.2 (development headers required)

Build
-----

```
$ ./waf configure
$ ./waf build
```

Run
---

```
$ build/kvs --configpath kvs_config.json &
$ build/client
```

Generating Server/Keeper/Client from IDL
----------------------------------------

For your convenience, `generate` target is already defined in `wscript` (note that `jenerator` must be in `PATH`).

```
$ ./waf generate
```

It actually does the following:

```
$ jenerator -l server -o . -n jubatus -t kvs.idl
```
