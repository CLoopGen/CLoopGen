#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int chroma_stride = 32;
uint8_t *dest_u;
uint8_t *dest_v;
uint16_t val_no_chroma = 0x5A5A;
size_t mb_max_x = 1024;

size_t i;
size_t j;

void init_vars() {
    const size_t total_size = mb_max_x * 16 * sizeof(uint16_t);
    dest_u = aligned_alloc(32, total_size);
    dest_v = aligned_alloc(32, total_size);

    if (!dest_u || !dest_v) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
}