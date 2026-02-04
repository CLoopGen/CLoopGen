#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *dst;
int dst_step;
uint16_t *src;
int src_step;
int radius;
int inv;
int x;
int sum;

static uint16_t *src_storage;
static uint16_t *dst_storage;

void init_vars() {
    const size_t total_size = 128 * 1024 * 1024; // 128 MB of total data
    const size_t element_size = sizeof(uint16_t);
    const size_t num_elements = total_size / element_size / 2; // Split between src and dst

    src_storage = aligned_alloc(64, num_elements * element_size);
    dst_storage = aligned_alloc(64, num_elements * element_size);

    if (!src_storage || !dst_storage) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        src_storage[i] = rand() & 0xFFFF;
        dst_storage[i] = 0;
    }

    src = src_storage;
    dst = dst_storage;

    src_step = 1;
    dst_step = 1;

    radius = (int)(num_elements / 2) - 1;
    if (radius <= 0) radius = 1;

    inv = 0x10000; 

    x = 0;
    sum = 0;
}