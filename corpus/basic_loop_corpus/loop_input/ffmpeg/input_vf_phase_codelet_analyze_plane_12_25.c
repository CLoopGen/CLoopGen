#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1048576; // ~2MB of data (1M elements * 2 bytes each)
int64_t tdif = 0;
int64_t pdif = 0;
int t = 0;
uint16_t *rend;

void init_vars() {
    size_t num_elements = w + 2 * abs(ns) + 2; // Ensure room for ns offsets
    nptr = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));
    optr = (uint16_t*)aligned_alloc(32, num_elements * sizeof(uint16_t));

    for (size_t i = 0; i < num_elements; ++i) {
        nptr[i] = rand() % 100;
        optr[i] = rand() % 100;
    }

    rend = nptr + w;
}