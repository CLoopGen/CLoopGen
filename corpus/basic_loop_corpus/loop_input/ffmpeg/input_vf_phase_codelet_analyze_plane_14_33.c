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
int64_t tdif;
int64_t pdif;
int t;
uint16_t *rend;

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; 
    total_size = target_bytes / sizeof(uint16_t);
    w = total_size - (2 * abs(ns) + (os << 1)); 

    if (w <= 0) {
        w = total_size / 4;
        ns = 1;
        os = 1;
    }

    nptr_base = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    optr_base = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));

    if (!nptr_base || !optr_base) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        nptr_base[i] = rand() & 0xFFFF;
        optr_base[i] = rand() & 0xFFFF;
    }

    nptr = nptr_base;
    optr = optr_base;

    tdif = 0;
    pdif = 0;
    t = 0;

    ns = abs(ns) ? ns : 1;
    os = abs(os) ? os : 1;

    if (ns >= w || os >= w) {
        ns = w / 8;
        os = w / 8;
    }
}