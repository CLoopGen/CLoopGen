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
int64_t tdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t data_size;

void init_vars() {
    data_size = 131072; // ~256KB of data (131072 * 2 bytes * 2 arrays)

    nptr_base = (uint16_t*)aligned_alloc(64, data_size * sizeof(uint16_t));
    optr_base = (uint16_t*)aligned_alloc(64, data_size * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        nptr_base[i] = rand() & 0xFFFF;
        optr_base[i] = rand() & 0xFFFF;
    }

    nptr = nptr_base;
    optr = optr_base;

    bdif = 0;
    tdif = 0;
    t = 0;
    rend = nptr + w;
}