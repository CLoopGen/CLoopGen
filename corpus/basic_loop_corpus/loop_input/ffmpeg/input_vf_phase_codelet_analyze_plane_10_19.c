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
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size = 64 * 1024 * 1024; // ~64 MB for each array

void init_vars() {
    size_t num_elements = total_size / sizeof(uint16_t);
    w = num_elements - (ns << 1) - 1; // Ensure nptr[ns], nptr[ns<<1], nptr[-ns] are in bounds
    if (w <= 0) {
        w = 1;
    }

    nptr_base = aligned_alloc(32, (num_elements) * sizeof(uint16_t));
    optr_base = aligned_alloc(32, (num_elements) * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        exit(1);
    }

    for (size_t i = 0; i < num_elements; i++) {
        nptr_base[i] = rand() % 256;
        optr_base[i] = rand() % 256;
    }

    nptr = nptr_base + (ns << 1); // Start such that nptr[-ns] is valid
    optr = optr_base + (ns << 1);
    rend = nptr + w;
    bdif = 0;
    pdif = 0;
    t = 0;
}