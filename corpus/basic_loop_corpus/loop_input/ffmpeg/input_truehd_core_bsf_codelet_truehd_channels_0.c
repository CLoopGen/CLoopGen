#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t thd_chancount[13];
int chanmap;
int channels;
int i;

void init_vars() {
    for (i = 0; i < 13; i++) {
        thd_chancount[i] = (uint8_t)(i * 17 + 13); // Arbitrary non-zero initialization
    }
    chanmap = 0x1FFF;   // Set all 13 bits to 1 for full coverage
    channels = 0;       // Initialize accumulator to zero
}