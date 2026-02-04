#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (1 << 20)  // 1MB of data: 262144 integers (since each int is 4 bytes)

int markers[262144];
int i;
int sum;
int max;

void init_vars() {
    // Seed random number generator for non-trivial marker values
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&i));
    
    // Initialize the markers array with random values to ensure realistic computation
    for (size_t idx = 0; idx < sizeof(markers) / sizeof(markers[0]); idx++) {
        markers[idx] = rand() % 10000;  // Random values between 0 and 9999
    }

    // Initialize loop control and accumulation variables
    i = 0;
    sum = 0;
    max = 0;  // Safe initial index within bounds
}