#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t bdif;
extern int64_t tdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed indices for better spatial locality
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;
    int stride = os;
    int n_stride = ns;
    for (int i = 0; i < w; i++) {
        int n_idx = i;
        int o_idx = i;
        bdif += ((t) = (((nptr_base[n_idx]) - optr_base[o_idx + stride]) << 2) +
                      nptr_base[n_idx + (n_stride << 1)] - optr_base[o_idx - stride],
                      (t) * (t));
        tdif += ((t) = (((optr_base[o_idx]) - nptr_base[n_idx + n_stride]) << 2) +
                      optr_base[o_idx + (stride << 1)] - nptr_base[n_idx - n_stride],
                      (t) * (t));
    }
}
