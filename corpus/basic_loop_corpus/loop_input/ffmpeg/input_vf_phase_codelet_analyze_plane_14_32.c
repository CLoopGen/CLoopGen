#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size_bytes = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime

void init_vars() {
    size_t num_elements = total_size_bytes / sizeof(uint16_t);
    w = num_elements - (abs(ns) << 1) - 1; // Ensure nptr[ns], nptr[ns<<1], nptr[-ns] are valid
    if (w <= 0) {
        w = 1;
    }

    nptr_base = (uint16_t *)aligned_alloc(64, num_elements * sizeof(uint16_t));
    optr_base = (uint16_t *)aligned_alloc(64, num_elements * sizeof(uint16_t));

    for (size_t i = 0; i < num_elements; i++) {
        nptr_base[i] = (uint16_t)(i % 30000);
        optr_base[i] = (uint16_t)((i + 100) % 30000);
    }

    nptr = nptr_base + (abs(ns) << 1); // Start offset to allow access to [ns<<1] and [-ns]
    optr = optr_base + (abs(os) << 1);

    tdif = 0;
    pdif = 0;
    t = 0;
    rend = nptr + w;
}