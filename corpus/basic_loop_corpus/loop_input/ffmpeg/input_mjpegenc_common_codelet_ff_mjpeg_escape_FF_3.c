#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int size;
int i;
int ff_count;
uint8_t *buf;

void init_vars() {
    // Allocate approximately 64MB of data to target ~0.01s runtime on modern CPUs
    size = 64 * 1024 * 1024;
    buf = (uint8_t *)malloc(size);
    if (!buf) {
        exit(1);
    }

    // Initialize buffer with pseudo-random data for realistic processing
    srand(time(NULL));
    for (int j = 0; j < size; j++) {
        buf[j] = rand() & 0xFF;
    }

    // Ensure loop bounds are safe: i < size - 15, stepping by 16
    i = 0;
    ff_count = 0;
}

// Explicitly allow linking with externally defined loop function