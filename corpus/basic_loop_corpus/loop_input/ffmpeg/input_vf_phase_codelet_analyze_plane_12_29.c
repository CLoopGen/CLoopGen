#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 65536;
int64_t bdif = 0;
int64_t tdif = 0;
int t = 0;
uint16_t *rend;

static uint16_t *narr;
static uint16_t *oarr;

void init_vars() {
    size_t data_size = 131072; // ~256KB of data (each element is 2 bytes)

    narr = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));
    oarr = (uint16_t*)aligned_alloc(32, data_size * sizeof(uint16_t));

    if (!narr || !oarr) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        narr[i] = (uint16_t)(i & 0xFFFF);
        oarr[i] = (uint16_t)((i + 100) & 0xFFFF);
    }

    nptr = narr;
    optr = oarr;

    w = 65536; // ensures loop runs for 65536 iterations
    ns = 1;
    os = 1;
    bdif = 0;
    tdif = 0;
    t = 0;
}