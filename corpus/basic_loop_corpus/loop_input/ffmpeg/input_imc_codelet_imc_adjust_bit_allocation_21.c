#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

float workT[32];
int i;
float highest;
int found_indx;

void init_vars() {
    // Initialize the workT array with random float values
    srand(time(NULL));
    for (int idx = 0; idx < 32; idx++) {
        workT[idx] = ((float)rand() / RAND_MAX) * 100.0f; // Random floats between 0 and 100
    }

    // Initialize loop control and tracking variables
    i = 0;
    highest = workT[0];   // Initialize to first element to ensure correct comparison
    found_indx = 0;
}