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
    // Variant 1: Consecutive memory access with pre-computed array offsets for nptr and optr
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;
    for (int i = 0; i < w; i++) {
        int idx_n = i;
        int idx_ns = i + ns;
        int idx_2ns = i + (ns << 1);
        int idx_neg_ns = i - ns;

        pdif += ((t) = ((nptr_base[idx_n] - nptr_base[idx_ns]) << 2) + nptr_base[idx_2ns] - nptr_base[idx_neg_ns], (t) * (t));
        
        int idx_os = i + os;
        int idx_neg_os = i - os;
        tdif += ((t) = ((nptr_base[idx_n] - optr_base[idx_os]) << 2) + nptr_base[idx_2ns] - optr_base[idx_neg_os], (t) * (t));
    }
}
