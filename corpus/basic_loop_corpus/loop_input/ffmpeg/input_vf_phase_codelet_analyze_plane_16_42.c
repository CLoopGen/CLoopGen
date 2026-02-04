#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 65536;
int64_t bdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t data_size = 131072; // ~256KB of data (65536 * 2 * 2)

void init_vars() {
    nptr_base = (uint16_t*)aligned_alloc(64, data_size * sizeof(uint16_t));
    optr_base = (uint16_t*)aligned_alloc(64, data_size * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        nptr_base[i] = (uint16_t)(i & 0xFFFF);
        optr_base[i] = (uint16_t)((i + 100) & 0xFFFF);
    }

    nptr = nptr_base + 1;  // leave space for negative index access
    optr = optr_base + 1;
    w = data_size - 2;     // ensure ns=1 is safe for all accesses: [ns], [-ns], [ns<<1]
    ns = 1;
    os = 1;
    rend = nptr + w;
    bdif = 0;
    pdif = 0;
    t = 0;
}