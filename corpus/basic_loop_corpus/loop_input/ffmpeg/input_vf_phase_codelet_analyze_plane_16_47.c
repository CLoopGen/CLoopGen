#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
    // Aim for approximately 64MB of data per array to target ~0.01 sec runtime on modern CPUs
    total_size = 32 * 1024 * 1024; // ~64MB total (two arrays of 32M uint16_t = 64MB)
    
    nptr_base = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    optr_base = (uint16_t*)aligned_alloc(32, total_size * sizeof(uint16_t));
    
    if (!nptr_base || !optr_base) {
        exit(1);
    }

    for (size_t i = 0; i < total_size; i++) {
        nptr_base[i] = (uint16_t)(i & 0xFFFF);
        optr_base[i] = (uint16_t)((i ^ 0x5555) & 0xFFFF);
    }

    // Set accessible window size 'w' such that all strided accesses stay in bounds
    // Maximum absolute stride: max(|ns|, |os|) and we access up to [-(stride)] and [(stride)<<1]
    // So we require: w + 2*max_stride <= total_size
    ns = 3;
    os = 4;
    w = total_size - (2 * (ns > os ? ns : os)) - 1;  // leave margin for worst-case indexing

    nptr = nptr_base;
    optr = optr_base;

    // Initialize accumulators
    bdif = 0;
    tdif = 0;
    pdif = 0;
    t = 0;
    rend = nptr + w;
}