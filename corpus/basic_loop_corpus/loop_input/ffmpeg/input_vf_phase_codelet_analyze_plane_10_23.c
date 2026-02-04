#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 16;
int os = 16;
uint16_t *nptr;
uint16_t *optr;
int w = 1048576; // ~2MB of data (1M elements * 2 bytes each)
int64_t bdif;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_data_size = 1048576 * sizeof(uint16_t);

void init_vars() {
    nptr_base = (uint16_t*)aligned_alloc(32, total_data_size + 32 * sizeof(uint16_t));
    optr_base = (uint16_t*)aligned_alloc(32, total_data_size + 32 * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        exit(1);
    }

    for (size_t i = 0; i < (total_data_size / sizeof(uint16_t)) + 32; i++) {
        nptr_base[i] = rand() % 256;
        optr_base[i] = rand() % 256;
    }

    nptr = nptr_base + 16;
    optr = optr_base + 16;
    w = 1048576;

    bdif = 0;
    tdif = 0;
    pdif = 0;
}