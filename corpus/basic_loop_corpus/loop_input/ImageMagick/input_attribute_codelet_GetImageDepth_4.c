#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
size_t number_threads = 256 * 1024; // Adjusted for ~0.01 sec runtime
size_t *current_depth;

void init_vars() {
    current_depth = (size_t*)calloc(number_threads, sizeof(size_t));
    if (!current_depth) {
        exit(1);
    }
}