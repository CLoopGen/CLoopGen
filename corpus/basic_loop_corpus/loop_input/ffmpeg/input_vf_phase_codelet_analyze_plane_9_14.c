#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ns;
int os;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t bdif;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size;

void init_vars() {
    ns = 16;
    os = 16;
    w = 1 << 20; // 1M elements per array
    total_size = w + (ns << 1) + ns; // accommodate offsets: [ns], [2*ns], [-ns]

    nptr_base = aligned_alloc(32, total_size * sizeof(uint16_t));
    optr_base = aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        nptr_base[i] = rand() & 0xFFFF;
        optr_base[i] = rand() & 0xFFFF;
    }

    nptr = nptr_base + ns;
    optr = optr_base + os;
    rend = nptr + w;

    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;
}