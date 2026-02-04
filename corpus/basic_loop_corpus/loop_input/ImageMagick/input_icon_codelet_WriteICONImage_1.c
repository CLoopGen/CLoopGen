#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
unsigned char *q;
unsigned short bits_per_pixel;

static unsigned char *q_storage;

void init_vars() {
    bits_per_pixel = 24;
    ssize_t num_iterations = (ssize_t)1UL << bits_per_pixel;
    size_t data_size = num_iterations * 4;
    q_storage = aligned_alloc(32, data_size);
    if (!q_storage) {
        exit(1);
    }
    q = q_storage;
    i = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(q_storage);
}