# cbf - simple brainfuck interpreter
cbf is a [brainfuck](https://en.wikipedia.org/wiki/Brainfuck)
interpreter written in C99. That's it really.

## Usage
Upon startup, the program reads brainfuck code from standard
input. Then it executes it and reads additional data from stdin
and outputs to stdout.

*Also after successfull shutdown it writes one additional `\n` to stdout.*

## Building
It's simple, really.
 1. get GCC,
 2. get CMake,
 3. get GNU Make.

Create a directory `build` in repository's root directory,
and execute `cmake ..` from it. Now run `make all`. `cbf`
executable should appear in `build` directory.

## License
This program and its source code is [unlicensed](http://unlicense.org).