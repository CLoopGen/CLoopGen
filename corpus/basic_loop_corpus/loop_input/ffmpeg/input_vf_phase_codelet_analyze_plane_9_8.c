#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 32 * 1024 * 1024; // ~64MB of data (32M elements * 2 bytes each)
int64_t tdif = 0;
int64_t pdif = 0;
int t = 0;
uint16_t *rend;

uint16_t *narr;
uint16_t *oarr;

void init_vars() {
    size_t total_size = w + (2 * abs(ns)) + 1;
    narr = aligned_alloc(32, total_size * sizeof(uint16_t));
    oarr = aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!narr || !oarr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        narr[i] = rand() & 0xFFFF;
        oarr[i] = rand() & 0xFFFF;
    }

    nptr = narr + abs(ns);
    optr = oarr + abs(os);
    rend = nptr + w;

    tdif = 0;
    pdif = 0;
}