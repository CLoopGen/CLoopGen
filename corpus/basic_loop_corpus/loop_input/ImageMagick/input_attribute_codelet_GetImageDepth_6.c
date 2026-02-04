#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
size_t *current_depth;
size_t depth;
size_t number_threads = 1024;

void init_vars() {
    current_depth = (size_t*)calloc(number_threads, sizeof(size_t));
    if (!current_depth) {
        exit(1);
    }
    for (size_t idx = 0; idx < number_threads; idx++) {
        current_depth[idx] = rand() % 1000;
    }
    depth = 0;
    i = 0;
}