#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

int i;
float lowest;
int low_indx;
float workT[32];

void init_vars() {
    // Initialize loop index
    i = 0;

    // Initialize tracking variables
    low_indx = 0;

    // Seed random number generator for realistic data
    srand((unsigned int)time(NULL));

    // Initialize workT with random float values between 1.0 and 1000.0
    for (int idx = 0; idx < 32; idx++) {
        workT[idx] = 1.0f + (999.0f * rand()) / RAND_MAX;
    }

    // Initialize lowest with the first element to ensure correct reduction behavior
    lowest = workT[0];
    low_indx = 0;
}