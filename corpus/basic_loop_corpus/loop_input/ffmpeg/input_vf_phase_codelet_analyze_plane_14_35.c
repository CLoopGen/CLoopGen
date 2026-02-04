#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1 << 20; // Approximately 1MB of data (w = 1M elements)
int64_t bdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *n_array;
static uint16_t *o_array;

void init_vars() {
    size_t total_size = w + (abs(ns) << 1) + 1; // Ensure room for ns offsets
    n_array = aligned_alloc(32, total_size * sizeof(uint16_t));
    o_array = aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!n_array || !o_array) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        n_array[i] = rand() & 0xFFFF;
        o_array[i] = rand() & 0xFFFF;
    }

    nptr = n_array + (abs(ns) << 1);
    optr = o_array + (abs(os) << 1);
    rend = nptr + w;
    bdif = 0;
    pdif = 0;
    t = 0;
}