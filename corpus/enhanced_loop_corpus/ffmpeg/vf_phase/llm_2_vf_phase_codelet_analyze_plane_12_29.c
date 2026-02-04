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
    // Variant 1: Consecutive Memory Access with Reordered Array Traversal
    // Instead of incrementing nptr and optr separately, use indexing for sequential and aligned access.
    // This improves predictability and may enhance cache performance.
    int i;
    uint16_t *nbase = nptr;
    uint16_t *obase = optr;
    for (i = 0; i < w; i++) {
        int idx = i;
        bdif += ((t) = (((nbase[idx]) - obase[idx + os]) << 2) + nbase[idx + (ns << 1)] - obase[idx - os], (t) * (t));
        tdif += ((t) = (((obase[idx]) - nbase[idx + ns]) << 2) + obase[idx + (os << 1)] - nbase[idx - ns], (t) * (t));
    }
}
