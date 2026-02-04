#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int height = 1048576; // Approximately 1MB of data
int linesize = 1;
float o1 = 0.5f;
float o2 = 0.5f;
int v = 128;
int step = 1;
int y;

uint8_t *base_ptr;

void init_vars() {
    base_ptr = (uint8_t*)aligned_alloc(32, height * linesize);
    if (!base_ptr) {
        exit(1);
    }
    for (int i = 0; i < height * linesize; ++i) {
        base_ptr[i] = rand() % 256;
    }
    dst = base_ptr;
}