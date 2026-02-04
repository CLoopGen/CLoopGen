#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int shift2;
int x;
int bits;
int retval;
int bit_mask;
int guess;
int square;
int i;
int64_t accu;

void init_vars() {
    bits = 32;
    shift2 = 32;
    x = 0x5f3759df; 
    retval = 0;
    bit_mask = 1 << (bits - 1);
    guess = 0;
    square = 0;
    i = 0;
    accu = 0;
}