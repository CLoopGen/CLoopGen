#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/time.h>

ssize_t i;
size_t *current_depth;
size_t depth;
size_t number_threads;

void init_vars() {
    number_threads = 16;

    current_depth = (size_t*)malloc(number_threads * sizeof(size_t));
    if (!current_depth) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < number_threads; idx++) {
        current_depth[idx] = (idx + 1) * 1000;
    }

    depth = 500;
    i = 0;
}