#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ns = 1;
int os = 1;
uint8_t *nptr = NULL;
uint8_t *optr = NULL;
int w = 0;
int bdif = 0;
int pdif = 0;
int t = 0;
uint8_t *rend = NULL;

#define DATA_SIZE (64 * 1024 * 1024)  // 64 MB of data for ~0.01 sec runtime estimate

static uint8_t *nptr_base = NULL;
static uint8_t *optr_base = NULL;

void init_vars() {
    w = DATA_SIZE;

    nptr_base = aligned_alloc(32, w + 4 * abs(ns) + 32);
    optr_base = aligned_alloc(32, w + 4 * abs(os) + 32);

    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    nptr = nptr_base + 16;
    optr = optr_base + 16;

    for (int i = 0; i < w + 4 * abs(ns) + 16; i++) {
        nptr_base[i] = rand() % 256;
    }
    for (int i = 0; i < w + 4 * abs(os) + 16; i++) {
        optr_base[i] = rand() % 256;
    }

    bdif = 0;
    pdif = 0;
}