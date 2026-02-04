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
    // Variant 1: Consecutive memory access with precomputed base offsets
    // Instead of incrementing nptr and optr, use index-based addressing with stride=1
    // This changes pointer arithmetic to array indexing for better predictability
    uint16_t *nbase = nptr;
    uint16_t *obase = optr;
    for (int i = 0; i < w; i++) {
        int nidx = i;
        int oidx = i;
        bdif += ((t) = (((nbase[nidx]) - obase[oidx + os]) << 2) + 
                        nbase[nidx + (ns << 1)] - obase[oidx - os], (t) * (t));
        tdif += ((t) = (((obase[oidx]) - nbase[nidx + ns]) << 2) + 
                        obase[oidx + (os << 1)] - nbase[nidx - ns], (t) * (t));
    }
}
