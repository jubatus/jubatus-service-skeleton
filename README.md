Skelton of Service in Jubatus Framework
=======================================

This is an implementation of a simple key-value store that uses Jubatus framework.

Build
-----

```
$ ./waf configure
$ ./waf build
```

Run
---

```
$ build/kvs &
$ build/client
```

Generating Server/Keeper/Client from IDL
----------------------------------------

For your convenience, `generate` target is already defined in `wscript`.

```
$ ./waf generate
```

It actually does the following:

```
$ jenerator kvs.idl -o . -t
$ mpidl cpp kvs.idl -o . -p -n jubatus
```
