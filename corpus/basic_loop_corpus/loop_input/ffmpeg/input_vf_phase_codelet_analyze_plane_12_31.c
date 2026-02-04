#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1024 * 1024 / sizeof(uint16_t); // ~1MB of data
int64_t bdif = 0;
int64_t tdif = 0;
int64_t pdif = 0;
int t = 0;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t total_size = w + (2 * ns) + 2; // Add padding for safe indexing with offsets
    narr = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    oarr = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!narr || !oarr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        narr[i] = rand() % 256;
        oarr[i] = rand() % 256;
    }

    nptr = narr + ns;     // Start such that nptr[ns], nptr[2*ns], nptr[-ns] are valid
    optr = oarr + os;     // Same for optr

    rend = nptr + w;
}

__attribute__((destructor))
static void cleanup() {
    free(narr);
    free(oarr);
}