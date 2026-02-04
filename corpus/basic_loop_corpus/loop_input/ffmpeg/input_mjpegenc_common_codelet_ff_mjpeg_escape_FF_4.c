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
    const size_t input_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU
    size = (int)input_size;
    i = 0;
    ff_count = 0;

    buf = (uint8_t *)malloc(size);
    if (!buf) {
        exit(1);
    }

    // Initialize buffer with pseudo-random data including some 0xFF bytes
    srand((unsigned int)time(NULL));
    for (int j = 0; j < size; j++) {
        buf[j] = (uint8_t)rand();
    }
}