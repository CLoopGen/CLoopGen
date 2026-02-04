#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 65536; // Size chosen to process ~128KB of data (65536 elements * 2 bytes each for two arrays)
int64_t bdif;
int64_t tdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size;

void init_vars() {
    total_size = w + 4; // Add padding to prevent out-of-bounds access with offsets like [ns], [os], [-(os)], etc.
    nptr_base = aligned_alloc(32, total_size * sizeof(uint16_t));
    optr_base = aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        nptr_base[i] = rand() % 100;
        optr_base[i] = rand() % 100;
    }

    nptr = nptr_base + 1;   // Offset start to allow indexing like [-(ns)]
    optr = optr_base + 1;

    bdif = 0;
    tdif = 0;
    t = 0;
    rend = nptr + w;
}

__attribute__((destructor)) void cleanup() {
    free(nptr_base);
    free(optr_base);
}