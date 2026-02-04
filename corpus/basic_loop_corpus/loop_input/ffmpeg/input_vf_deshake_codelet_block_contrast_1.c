#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

uint8_t *src;
int x = 0;
int y = 0;
int stride;
int blocksize;
int highest = 0;
int lowest = 255;
int i;
int j;
int pos;

void init_vars() {
    blocksize = 1000;
    stride = 2048;
    int total_size = stride * (y + blocksize * 2 + 1);
    src = (uint8_t*)aligned_alloc(32, total_size * sizeof(uint8_t));
    
    if (!src) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (int idx = 0; idx < total_size; ++idx) {
        src[idx] = (uint8_t)(rand() % 256);
    }

    x = 0;
    y = 0;
    highest = 0;
    lowest = 255;
}