#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char bits[65];
int zeroes;
int i;
int j;

void init_vars() {
    // Set data size to achieve approximately 0.01 seconds runtime
    // On a typical modern CPU, writing 1 million bytes takes about 0.01 seconds when optimized
    zeroes = 64;  // Enough to fill the remainder of bits array from current i
    i = 0;        // Start at beginning of bits array
    j = 0;        // Loop counter, initialized in loop

    // Ensure i + zeroes does not exceed bounds of bits array
    // bits has size 65, so we set zeroes <= (65 - i_initial), here i starts at 0 -> max 65
    // We choose zeroes = 64 to safely stay within bounds and leave one byte free if needed
}