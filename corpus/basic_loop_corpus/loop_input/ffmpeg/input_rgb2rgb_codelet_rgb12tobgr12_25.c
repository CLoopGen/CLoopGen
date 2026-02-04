#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint16_t *d;
uint16_t *s;
int i;
int num_pixels;

void init_vars() {
    num_pixels = 67108864; // 64M elements * 2 bytes = 128MB total per array
    s = (uint16_t*)aligned_alloc(32, num_pixels * sizeof(uint16_t));
    d = (uint16_t*)aligned_alloc(32, num_pixels * sizeof(uint16_t));

    for (int idx = 0; idx < num_pixels; idx++) {
        s[idx] = (uint16_t)(idx % 4096);
    }

    i = 0;
}