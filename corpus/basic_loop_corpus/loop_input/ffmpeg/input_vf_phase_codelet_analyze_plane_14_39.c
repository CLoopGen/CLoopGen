#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t bdif;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to target ~0.01 sec runtime

static uint16_t *nptr_base;
static uint16_t *optr_base;

void init_vars() {
    // Allocate memory with padding to avoid out-of-bounds access
    const int max_offset_n = (ns << 1) + 1; // maximum forward and backward offset for nptr
    const int max_offset_o = (os << 1) + 1; // maximum forward and backward offset for optr
    const size_t total_n_size = DATA_SIZE + 2 * max_offset_n;
    const size_t total_o_size = DATA_SIZE + 2 * max_offset_o;

    nptr_base = aligned_alloc(32, total_n_size * sizeof(uint16_t));
    optr_base = aligned_alloc(32, total_o_size * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        exit(1);
    }

    // Initialize arrays with deterministic values
    for (size_t i = 0; i < total_n_size; i++) {
        nptr_base[i] = (uint16_t)(i * 7919) % 30000; // prime multiplier
    }
    for (size_t i = 0; i < total_o_size; i++) {
        optr_base[i] = (uint16_t)(i * 5779) % 30000; // another prime
    }

    // Set working pointers to the middle of allocated regions to allow safe indexing
    nptr = nptr_base + max_offset_n;
    optr = optr_base + max_offset_o;

    w = DATA_SIZE;

    // Ensure that during loop: nptr + w <= rend and all index accesses are valid
    // Accesses: nptr[ns], nptr[ns<<1], nptr[-ns] => need at least (ns<<1) head/tail room
    // Same for optr with os
}