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
    // Instead of incrementing nptr and optr separately, we use index-based access to ensure consecutive reads
    // and improve spatial locality. We also unroll the loop by a factor of 2 for better ILP.
    int i;
    uint16_t *nbase = nptr;
    uint16_t *obase = optr;
    for (i = 0; i < w - 1; i += 2) {
        int idx1 = i;
        int idx2 = i + 1;

        // First iteration of unroll
        tdif += ((t) = (((nbase[idx1]) - obase[idx1 + os]) << 2) + nbase[idx1 + (ns << 1)] - obase[idx1 - os], (t) * (t));
        bdif += ((t) = (((obase[idx1]) - nbase[idx1 + ns]) << 2) + obase[idx1 + (os << 1)] - nbase[idx1 - ns], (t) * (t));

        // Second iteration of unroll
        tdif += ((t) = (((nbase[idx2]) - obase[idx2 + os]) << 2) + nbase[idx2 + (ns << 1)] - obase[idx2 - os], (t) * (t));
        bdif += ((t) = (((obase[idx2]) - nbase[idx2 + ns]) << 2) + obase[idx2 + (os << 1)] - nbase[idx2 - ns], (t) * (t));
    }

    // Handle remaining element if w is odd
    if (i < w) {
        tdif += ((t) = (((nbase[i]) - obase[i + os]) << 2) + nbase[i + (ns << 1)] - obase[i - os], (t) * (t));
        bdif += ((t) = (((obase[i]) - nbase[i + ns]) << 2) + obase[i + (os << 1)] - nbase[i - ns], (t) * (t));
    }
}
