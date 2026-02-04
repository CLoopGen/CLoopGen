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
    // Variant 1: Consecutive memory access with stride-2 traversal (unrolled-like pattern)
    uint16_t *nend = nptr + w - 1; // Adjust to ensure pair access is safe
    for (; nptr < nend; nptr += 2, optr += 2) {
        int t1, t2;
        // First element of the pair
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[ns << 1] - optr[-os];
        bdif += t1 * t1;
        t1 = ((*(optr) - nptr[ns]) << 2) + optr[os << 1] - nptr[-ns];
        tdif += t1 * t1;

        // Second element of the pair
        t2 = (((nptr[1]) - optr[1 + os]) << 2) + nptr[(ns << 1) + 1] - optr[1 - os];
        bdif += t2 * t2;
        t2 = (((optr[1]) - nptr[1 + ns]) << 2) + optr[(os << 1) + 1] - nptr[1 - ns];
        tdif += t2 * t2;
    }
    // Handle remaining element if w was odd
    if (nptr == nend + 1) {
        t = ((*(nptr) - optr[os]) << 2) + nptr[ns << 1] - optr[-os];
        bdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[os << 1] - nptr[-ns];
        tdif += t * t;
    }
}
