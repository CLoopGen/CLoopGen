#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef float real_t;

real_t *arr;
int length;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64 MB of data for sufficient runtime (~0.01 sec on modern CPU)
    length = data_size / sizeof(real_t);
    arr = (real_t*)aligned_alloc(32, length * sizeof(real_t));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}