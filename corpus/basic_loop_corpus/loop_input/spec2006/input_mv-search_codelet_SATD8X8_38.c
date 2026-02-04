#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int *diff;
int j;
int m1[8][8];
int m2[8][8];

void init_vars() {
    const int data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    static int diff_storage[64 * 1024 * 1024];

    // Ensure data_size is large enough for all accesses: j << 3 + 7, max j=7 -> offset 63
    // So we only need at least 64 elements, but we use large buffer for timing

    // Initialize diff to point to the large storage
    diff = diff_storage;

    // Seed random number generator for realistic initialization
    srand(time(NULL));

    // Initialize diff with pseudo-random data to prevent optimization and ensure memory traffic
    for (int i = 0; i < data_size; i++) {
        diff[i] = rand() % 1000 - 500; // Small integers in range [-500, 499]
    }

    // Initialize m1 and m2 arrays to zero to ensure defined behavior
    memset(m1, 0, sizeof(m1));
    memset(m2, 0, sizeof(m2));

    // Initialize j to 0 as it's used as loop counter
    j = 0;
}