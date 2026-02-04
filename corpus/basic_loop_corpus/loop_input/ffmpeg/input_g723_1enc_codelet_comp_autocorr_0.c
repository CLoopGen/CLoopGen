#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

#define ARRAY_SIZE 180

int16_t hamming_window[ARRAY_SIZE];
int i;
int16_t vector[ARRAY_SIZE];

void init_vars() {
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        hamming_window[idx] = (int16_t)(0.54 - 0.46 * 2932); // Fixed-point approximation of Hamming window coefficient
        vector[idx] = (int16_t)(idx & 0x7FFF);
    }
}