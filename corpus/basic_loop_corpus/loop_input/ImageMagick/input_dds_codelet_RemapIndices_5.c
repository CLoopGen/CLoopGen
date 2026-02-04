#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t *map;
unsigned char *source;
unsigned char *target;
ssize_t i;

#define DATA_SIZE (64 * 1024 * 1024) // ~64 MB to target ~0.01 sec runtime

void init_vars() {
    map = (ssize_t*)aligned_alloc(sizeof(ssize_t), DATA_SIZE);
    source = (unsigned char*)aligned_alloc(1, DATA_SIZE);
    target = (unsigned char*)aligned_alloc(1, DATA_SIZE);

    if (!map || !source || !target) {
        exit(EXIT_FAILURE);
    }

    for (size_t idx = 0; idx < DATA_SIZE / sizeof(ssize_t); idx++) {
        if (idx < 16) {
            map[idx] = (rand() % 2 == 0) ? -1 : rand() % (DATA_SIZE);
        } else {
            map[idx] = rand() % (DATA_SIZE);
        }
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        source[idx] = (unsigned char)(rand() % 256);
        target[idx] = 0;
    }
}