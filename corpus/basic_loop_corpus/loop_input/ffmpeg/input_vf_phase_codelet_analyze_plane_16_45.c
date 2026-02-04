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

static uint16_t *nptr_base;
static uint16_t *optr_base;
static size_t total_size;

void init_vars() {
    total_size = 131072; // ~256KB of data (131072 * 2 bytes per uint16_t)
    
    nptr_base = aligned_alloc(64, total_size * sizeof(uint16_t));
    optr_base = aligned_alloc(64, total_size * sizeof(uint16_t));
    
    if (!nptr_base || !optr_base) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    
    for (size_t i = 0; i < total_size; i++) {
        nptr_base[i] = rand() % 1000;
        optr_base[i] = rand() % 1000;
    }
    
    nptr = nptr_base;
    optr = optr_base;
}