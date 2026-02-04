#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int16_t codetable[128][5];
int cb_coef;
int i;
double sumsum;
float buffer[5];

void init_vars() {
    // Initialize codetable with non-zero values to ensure meaningful computation
    for (int idx = 0; idx < 128; idx++) {
        for (int j = 0; j < 5; j++) {
            codetable[idx][j] = (int16_t)(idx * 5 + j - 64);
        }
    }

    // Set cb_coef within valid range [0,127]
    cb_coef = 64;

    // Initialize sumsum to a non-trivial value
    sumsum = 3.14159;

    // Initialize buffer to zero to avoid undefined behavior if used before loop
    for (int j = 0; j < 5; j++) {
        buffer[j] = 0.0f;
    }

    // Ensure consistent state for loop index
    i = 0;
}