#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1 << 20; // Approximately 1 million elements for ~0.01 sec runtime
int64_t bdif;
int64_t tdif;
int t;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t data_size = w + 4; // Add padding to prevent out-of-bounds access due to indexing like [ns], [-(os)], etc.
    narr = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    oarr = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));

    if (!narr || !oarr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        narr[i] = rand() % 256;
        oarr[i] = rand() % 256;
    }

    nptr = narr + 2; // Offset to allow negative indexing like -(ns)
    optr = oarr + 2;

    bdif = 0;
    tdif = 0;
    t = 0;
    rend = nptr + w;
}