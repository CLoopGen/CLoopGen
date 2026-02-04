#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *h_offsets;

void init_vars() {
    size_t num_elements = 1 << 10;
    h_offsets = (unsigned int*)calloc(num_elements, sizeof(unsigned int));
}

void loop();