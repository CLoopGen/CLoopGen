#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w;
int64_t bdif;
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

#define DATA_SIZE (128 << 20) // 128 MB total data

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_elements;

void init_vars() {
    total_elements = DATA_SIZE / sizeof(uint16_t);
    w = total_elements - 4; // ensure we can access [ns], [(ns)<<1], and [-(ns)] safely with ns=1
    if (w <= 0) {
        w = 1;
        total_elements = 5;
    }

    nptr_base = aligned_alloc(64, total_elements * sizeof(uint16_t));
    optr_base = aligned_alloc(64, total_elements * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_elements; i++) {
        nptr_base[i] = rand() & 0xFFFF;
        optr_base[i] = rand() & 0xFFFF;
    }

    nptr = nptr_base + 2; // offset to allow [-ns] and [-(ns)] indexing safely
    optr = optr_base + 2;

    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;
    rend = nptr + w;
}