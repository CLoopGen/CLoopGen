#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;
    int64_t local_accum = 0;
    int stride_n = ns;
    int stride_o = os;
    // Introduce loop-carried dependency via cumulative sum in 'local_accum'
    for (int i = 0; i < w; i++) {
        uint16_t val_n = nptr_base[i];
        uint16_t neighbor_n1 = nptr_base[i + stride_n];
        uint16_t neighbor_n2 = nptr_base[i + (stride_n << 1)];
        uint16_t neighbor_n3 = nptr_base[i - stride_n];
        int diff_p = ((val_n - neighbor_n1) << 2) + neighbor_n2 - neighbor_n3;
        int contrib_p = diff_p * diff_p;

        uint16_t neighbor_o1 = optr_base[i + stride_o];
        uint16_t neighbor_o2 = optr_base[i - stride_o];
        int diff_t = ((val_n - neighbor_o1) << 2) + neighbor_n2 - neighbor_o2;
        int contrib_t = diff_t * diff_t;

        // Create WAW and RAW dependencies: update shared accumulator sequentially
        local_accum += contrib_p + contrib_t;
    }
    // Fold accumulated result into global variables at end to remove per-iteration memory dependence
    pdif += local_accum / 2;
    tdif += local_accum - (local_accum / 2);
}
