#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 4;
int os = 4;
uint16_t *nptr;
uint16_t *optr;
int w = 1 << 20; // 1MB of data: 524,288 elements (each uint16_t is 2 bytes)
int64_t bdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t total_n_size = w + (ns << 1);
    size_t total_o_size = w + (os << 1);

    narr = (uint16_t*)aligned_alloc(32, total_n_size * sizeof(uint16_t));
    oarr = (uint16_t*)aligned_alloc(32, total_o_size * sizeof(uint16_t));

    if (!narr || !oarr) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_n_size; i++) {
        narr[i] = (uint16_t)(i % 32768);
    }
    for (size_t i = 0; i < total_o_size; i++) {
        oarr[i] = (uint16_t)((i + 100) % 32768);
    }

    nptr = narr + (ns << 1); 
    optr = oarr + (os << 1); 

    bdif = 0;
    pdif = 0;
}