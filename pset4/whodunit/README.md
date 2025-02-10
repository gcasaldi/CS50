# Specification
#### Implement a program called `whodunit` that reveals Mr. Boddy’s drawing in such a way that you can recognize whodunit:

* Implement your program in a file called `whodunit.c` in a directory called `whodunit`.

* Your program should accept exactly two command-line arguments: the name of an input file to open for reading followed by the name of an output file to open for writing.

* If your program is executed with fewer or more than two command-line arguments, it should remind the user of correct usage, as with  `fprintf` (to `stderr`), and `main` should return `1`.

* If the input file cannot be opened for reading, your program should inform the user as much, as with `fprintf` (to `stderr`), and `main` should return `2`.

* If the output file cannot be opened for writing, your program should inform the user as much, as with `fprintf` (to `stderr`), and `main` should return `3`.

* If the input file is not a 24-bit uncompressed BMP 4.0, your program should inform the user as much, as with `fprintf` (to `stderr`), and `main` should return `4`.

* Upon success, `main` should `0`.
