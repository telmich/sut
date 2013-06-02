SUT: Simple Universal Time
==========================

This repository contains a C file that prints the current SUT.


Running
-------

To run SUT.c simply run the executable file called `sut` in the repository directory.

```
./sut
```

If it says something like './sut: Permission denied' you will first need to give it permissions like so:

```
chmod +x sut
```

Building from Source
--------------------

To compile on Linux (with build-essential already installed) run: 

```
gcc sut.c -lm -o sut
```

This utility was inspired by http://telmich.github.io/sut/ and built for the purpose of being able to embed SUT in my statusbar on Linux.
