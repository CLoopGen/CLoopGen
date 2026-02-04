#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1024 * 512; // ~1MB of data (512K elements * 2 bytes)
int64_t bdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *n_array;
static uint16_t *o_array;

void init_vars() {
    const size_t total_size = w + 2 * abs(ns); // account for ns offsets

    n_array = aligned_alloc(32, total_size * sizeof(uint16_t));
    o_array = aligned_alloc(32, (w + 2 * abs(os)) * sizeof(uint16_t));

    if (!n_array || !o_array) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        n_array[i] = rand() & 0xFFFF;
    }
    for (size_t i = 0; i < w + 2 * abs(os); i++) {
        o_array[i] = rand() & 0xFFFF;
    }

    nptr = n_array + abs(ns); 
    optr = o_array + abs(os);

    bdif = 0;
    pdif = 0;
    t = 0;
    rend = nptr + w;
}