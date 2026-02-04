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

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    const size_t data_size = 262144; // 512KB of data (262144 elements * 2 bytes)
    narr = aligned_alloc(32, data_size * sizeof(uint16_t));
    oarr = aligned_alloc(32, data_size * sizeof(uint16_t));

    for (size_t i = 0; i < data_size; i++) {
        narr[i] = rand() & 0xFFFF;
        oarr[i] = rand() & 0xFFFF;
    }

    nptr = narr;
    optr = oarr;
    rend = nptr + w;

    bdif = 0;
    pdif = 0;
}