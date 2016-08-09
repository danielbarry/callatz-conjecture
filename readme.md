# Read Me

## Background

This program has been written to compute positive integer numbers for the
Collatz Conjecture up to (2^128)-1 as seen on Numberphile [1]. There is also
some automated features for searching large sets of numbers for interesting
properties.

[1] https://www.youtube.com/watch?v=5mFpVDpKX70

## Compiling

Run the following command:

    g++ -std=c++11 main.cc -o cc

## Running

To run the program, simply type:

    ./cc

This will show the available options.

### Example

The largest number this program can currently compute is
340282366920938463463374607431768211455 or (2^128)-1. This can be run with:

    ./cc 340282366920938463463374607431768211455 1 1

The output should be the following is compiled correctly:

    340282366920938463463374607431768211455     1143

The first number if the number computed, the second is the number of steps it
took to compute down to one.
