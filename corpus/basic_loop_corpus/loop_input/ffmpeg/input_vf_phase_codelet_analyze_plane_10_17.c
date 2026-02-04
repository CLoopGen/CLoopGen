#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint16_t *nptr;
uint16_t *optr;
int w = 1 << 20; // ~2MB of data (1M elements * 2 bytes)
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

void init_vars() {
    size_t total_size_n = w + 2 * abs(ns) + 1;
    size_t total_size_o = w + 2 * abs(os) + 1;

    uint16_t *n_base = aligned_alloc(32, total_size_n * sizeof(uint16_t));
    uint16_t *o_base = aligned_alloc(32, total_size_o * sizeof(uint16_t));

    for (size_t i = 0; i < total_size_n; i++) {
        n_base[i] = rand() % 256;
    }
    for (size_t i = 0; i < total_size_o; i++) {
        o_base[i] = rand() % 256;
    }

    nptr = n_base + abs(ns);
    optr = o_base + abs(os);

    tdif = 0;
    pdif = 0;
}