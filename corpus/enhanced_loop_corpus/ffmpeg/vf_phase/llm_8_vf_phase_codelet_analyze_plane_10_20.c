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
    // Variant 1: Increased computational intensity with unrolled operations and doubled arithmetic impact
    // Unroll by 2 iterations manually to reduce loop overhead and increase operation density per iteration
    uint16_t *nptr_end = nptr + w - 1;  // Adjust for unrolling (process pairs)
    for (rend = nptr + w; nptr < nptr_end; nptr += 2, optr += 2) {
        int64_t t1, t2;

        // First iteration of unrolled pair
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[ns << 1] - optr[-os];
        tdif += t1 * t1;
        t1 = ((*(optr) - nptr[ns]) << 2) + optr[os << 1] - nptr[-ns];
        bdif += t1 * t1;

        // Second iteration of unrolled pair
        t2 = ((nptr[1] - optr[1 + os]) << 2) + nptr[(ns << 1) + 1] - optr[1 - os];
        tdif += t2 * t2;
        t2 = ((optr[1] - nptr[1 + ns]) << 2) + optr[(os << 1) + 1] - nptr[1 - ns];
        bdif += t2 * t2;
    }

    // Handle leftover iteration if w is odd
    if (nptr < rend) {
        tdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
        bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
        nptr++; optr++;
    }
}
