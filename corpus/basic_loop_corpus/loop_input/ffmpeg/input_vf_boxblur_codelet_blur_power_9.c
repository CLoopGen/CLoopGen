#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int dst_step;
int len;
uint8_t *a;
int i;

static uint8_t *internal_a;
static uint8_t *internal_dst;

void init_vars() {
    len = 65536; // Number of elements to process
    dst_step = 2; // Each destination element is 2 bytes apart

    // Allocate arrays: 'a' contains packed uint16_t values, so we need 2 * len bytes
    internal_a = (uint8_t *)aligned_alloc(16, len * sizeof(uint16_t));
    internal_dst = (uint8_t *)aligned_alloc(16, len * dst_step * sizeof(uint8_t));

    if (!internal_a || !internal_dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    a = internal_a;
    dst = internal_dst;

    // Initialize input data
    for (int j = 0; j < len; j++) {
        ((uint16_t *)a)[j] = (uint16_t)(j & 0xFFFF);
    }
}