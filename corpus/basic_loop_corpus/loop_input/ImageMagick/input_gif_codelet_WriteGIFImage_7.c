#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

size_t bits_per_pixel;
size_t one;
ssize_t i;
unsigned char *q;

static unsigned char *q_storage;

void init_vars() {
    one = 1;
    bits_per_pixel = 20; // This makes one << bits_per_pixel = 1 << 20 = 1048576
    size_t total_elements = one << bits_per_pixel;
    size_t total_bytes = total_elements * 3; // Each iteration writes 3 bytes

    q_storage = aligned_alloc(32, total_bytes);
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