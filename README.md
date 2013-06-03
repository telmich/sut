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

Credits
-------

This utility was created based on a specification by Nico Schottelius.

The Original Proposal: http://www.nico.schottelius.org/docs/sut/

The Javascript Implementation: http://telmich.github.io/sut/

License
-------
This is licenced under the GPL-2.0 licence. (Think it should be a different licence? send me a message).