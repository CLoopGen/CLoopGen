#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1024 * 1024 / sizeof(uint16_t); // ~1MB of data
int64_t tdif = 0;
int64_t pdif = 0;
int t = 0;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;

void init_vars() {
    size_t total_size_n = w + 2 * abs(ns) + 1;
    size_t total_size_o = w + 2 * abs(os) + 1;

    nptr_base = aligned_alloc(32, total_size_n * sizeof(uint16_t));
    optr_base = aligned_alloc(32, total_size_o * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < total_size_n; i++) {
        nptr_base[i] = rand() % 256;
    }
    for (size_t i = 0; i < total_size_o; i++) {
        optr_base[i] = rand() % 256;
    }

    nptr = nptr_base + abs(ns);
    optr = optr_base + abs(os);
    rend = nptr + w;
}