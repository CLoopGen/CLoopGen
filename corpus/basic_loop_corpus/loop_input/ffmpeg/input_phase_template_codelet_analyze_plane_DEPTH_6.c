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
    size_t total_size_n = w + (ns << 1) + abs(-ns);
    size_t total_size_o = w + (os << 1) + abs(-os);

    narr = calloc(total_size_n, sizeof(uint16_t));
    oarr = calloc(total_size_o, sizeof(uint16_t));

    if (!narr || !oarr) {
        exit(1);
    }

    nptr = narr + abs(-ns);
    optr = oarr + abs(-os);

    for (size_t i = 0; i < total_size_n; i++) {
        narr[i] = rand() & 0xFFFF;
    }
    for (size_t i = 0; i < total_size_o; i++) {
        oarr[i] = rand() & 0xFFFF;
    }

    bdif = 0;
    tdif = 0;
    pdif = 0;
}