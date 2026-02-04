#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

unsigned int i;
uint8_t t;
uint8_t *l;

static uint8_t *l_storage;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB to target ~0.01 sec runtime on modern CPU
    l_storage = (uint8_t*)malloc(data_size);
    if (!l_storage) {
        exit(1);
    }

    // Fill most of the array with non-matching values
    t = 42;
    memset(l_storage, t + 1, data_size - 1);

    // Place the termination value near the end to ensure loop stops before overflow
    l_storage[data_size - 1] = t;

    l = l_storage;
}