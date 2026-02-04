#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int x;
int bits;
int retval;
int bit_mask;
int guess;
int square;
int i;
int64_t accu;
int shift2;

void init_vars() {
    x = 1000000;
    bits = 31;
    retval = 0;
    bit_mask = 1 << 30;
    shift2 = 31;
    accu = 0;
    guess = 0;
    square = 0;
    i = 0;
}