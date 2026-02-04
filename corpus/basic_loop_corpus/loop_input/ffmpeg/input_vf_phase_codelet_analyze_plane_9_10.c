#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1024 * 512; // ~1MB of data (1024*512 elements * 2 bytes)
int64_t bdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *n_array;
static uint16_t *o_array;

void init_vars() {
    size_t total_size = w + (size_t)abs(ns) * 3;
    n_array = aligned_alloc(64, (total_size + 1) * sizeof(uint16_t));
    o_array = aligned_alloc(64, (total_size + 1) * sizeof(uint16_t));

    if (!n_array || !o_array) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        n_array[i] = rand() % 256;
        o_array[i] = rand() % 256;
    }

    nptr = n_array + abs(ns); 
    optr = o_array + abs(os);
}