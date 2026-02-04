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
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    const size_t data_size = 262144; // ~512KB of data (2 arrays), ~0.01 sec estimate

    narr = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    oarr = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));

    if (!narr || !oarr) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        narr[i] = (uint16_t)(i % 30000);
        oarr[i] = (uint16_t)((i + 15000) % 30000);
    }

    nptr = narr + 1; 
    optr = oarr + 1;
    w = data_size - 4;

    ns = 1;
    os = 1;

    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;
    rend = nptr + w;
}