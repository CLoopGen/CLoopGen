#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint8_t *nptr;
uint8_t *optr;
int w = 64 * 1024 * 1024; // ~64 million elements to target ~0.01 sec runtime
int tdif = 0;
int pdif = 0;
int t = 0;
uint8_t *rend;

static uint8_t *nptr_base;
static uint8_t *optr_base;

void init_vars() {
    nptr_base = (uint8_t*)aligned_alloc(32, w + 4 * ns);
    optr_base = (uint8_t*)aligned_alloc(32, w + 4 * os);
    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < w + 4 * ns; i++) {
        nptr_base[i] = rand() % 256;
    }
    for (size_t i = 0; i < w + 4 * os; i++) {
        optr_base[i] = rand() % 256;
    }

    nptr = nptr_base + 2 * ns;
    optr = optr_base + 2 * os;
}