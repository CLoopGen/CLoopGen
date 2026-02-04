#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t number_bins = 16777216; // ~128 MB for size_t (8 bytes per element)
size_t *histogram;
ssize_t i;

void init_vars() {
    histogram = (size_t*)calloc(number_bins, sizeof(size_t));
    if (!histogram) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}