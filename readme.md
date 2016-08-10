# Read Me

## Background

This program has been written to compute positive integer numbers for the
Collatz Conjecture up to (2^128)-1 as seen on Numberphile [1]. There is also
some automated features for searching large sets of numbers for interesting
properties.

[1] https://www.youtube.com/watch?v=5mFpVDpKX70

## Compiling

The following is required:

  * A Linux Operating System
  * G++ with a version that allows C++11

**NOTE:** This program uses `__int128` which is currently only offered by the
GNU compiler.

Run the following command:

    g++ -std=c++11 main.cc -o cc

## Running

To run the program, simply type:

    ./cc

This will show the available options.

### Example

The largest number this program can potentially compute is
340282366920938463463374607431768211455 or (2^128)-1. The reason this is
theoretical is because all computation must be under the maximum number of
(2^128)-1, so that:

    3n+1 <= (2^128)-1

An example would be:

    ./cc 17 1 1

The output should be the following is compiled correctly:

    17  12
    Program took: 54us

The first number if the number computed, the second is the number of steps it
took to compute down to one.

Below that, you are told how long the program took to compute - this one done
on a moderate speed laptop of 2016.
