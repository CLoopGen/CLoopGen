#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *h_offsets;

static unsigned int *h_offsets_data;

void init_vars() {
    size_t num_elements = (1 << 10) + 1;
    h_offsets_data = (unsigned int *)calloc(num_elements, sizeof(unsigned int));
    if (!h_offsets_data) {
        exit(1);
    }
    h_offsets = h_offsets_data;
}

__attribute__((destructor)) void cleanup() {
    free(h_offsets_data);
}