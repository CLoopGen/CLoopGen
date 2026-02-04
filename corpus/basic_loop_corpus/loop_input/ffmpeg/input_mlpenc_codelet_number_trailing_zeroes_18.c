#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t sample;
int bits;

void init_vars() {
    sample = 0x00FFFFFF; // Sets first 24 bits to 1, so loop will run exactly 24 iterations
    bits = 0;
}