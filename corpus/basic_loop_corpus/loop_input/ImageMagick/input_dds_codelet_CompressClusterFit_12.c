#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ssize_t besti;
ssize_t bestj;
ssize_t i;
unsigned char *o;
unsigned char unordered[16];

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    o = (unsigned char *)malloc(data_size);
    if (!o) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; idx++) {
        o[idx] = rand() % 16; // Ensure values are within [0,15] to index unordered safely
    }

    besti = 0;
    bestj = (ssize_t)data_size;

    memset(unordered, 0, 16);
}