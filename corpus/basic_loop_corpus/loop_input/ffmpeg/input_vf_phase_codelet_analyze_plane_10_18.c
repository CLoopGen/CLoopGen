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

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size = 1 << 20; // 1MB of data

void init_vars() {
    nptr_base = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    optr_base = (uint16_t *)calloc(total_size, sizeof(uint16_t));
    if (!nptr_base || !optr_base) {
        exit(1);
    }

    nptr = nptr_base + abs(ns);
    optr = optr_base + abs(os);
    w = (total_size / sizeof(uint16_t)) - 2 * abs(ns);

    for (size_t i = 0; i < total_size / sizeof(uint16_t); i++) {
        nptr_base[i] = rand() % 256;
        optr_base[i] = rand() % 256;
    }
}