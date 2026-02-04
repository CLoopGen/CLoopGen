#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int size;
int i;
int ff_count;
uint8_t *buf;
int align;

void init_vars() {
    size = 64 * 1024 * 1024;  // 64 MB for ~0.01 sec runtime on modern CPU
    align = size;
    ff_count = 0;
    buf = (uint8_t*)aligned_alloc(32, size);
    if (!buf) {
        exit(1);
    }
    // Initialize buffer with pseudo-random data where roughly 1/16 bytes are 255
    for (int j = 0; j < size; j++) {
        buf[j] = rand() % 256;
        // Ensure some 255 values without making ff_count predictable
        if (rand() % 16 == 0)
            buf[j] = 255;
    }
}