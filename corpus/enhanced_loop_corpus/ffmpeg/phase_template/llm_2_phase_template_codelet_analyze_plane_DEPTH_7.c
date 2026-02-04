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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching and Sequential Array Traversal
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;
    rend = nptr_base + w;
    for (int i = 0; nptr_base + i < rend; i++) {
        int idx = i;
        pdif += ((t) = (((nptr_base[idx]) - nptr_base[idx + ns]) << 2) + nptr_base[idx + (ns << 1)] - nptr_base[idx - ns], (t) * (t));
        bdif += ((t) = (((nptr_base[idx]) - optr_base[idx + os]) << 2) + nptr_base[idx + (ns << 1)] - optr_base[idx - os], (t) * (t));
        tdif += ((t) = (((optr_base[idx]) - nptr_base[idx + ns]) << 2) + optr_base[idx + (os << 1)] - nptr_base[idx - ns], (t) * (t));
    }
}
