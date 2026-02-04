#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1 << 24; // ~16 million iterations, approx 0.01s runtime with reasonable data size
int64_t bdif = 0;
int64_t tdif = 0;
int64_t pdif = 0;
int t;

uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t total_size = (w + (ns << 1)) * sizeof(uint16_t);
    narr = (uint16_t *)aligned_alloc(32, total_size);
    oarr = (uint16_t *)aligned_alloc(32, total_size);

    if (!narr || !oarr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < w + (ns << 1); i++) {
        narr[i] = rand() % 256;
        oarr[i] = rand() % 256;
    }

    nptr = narr;
    optr = oarr;
}