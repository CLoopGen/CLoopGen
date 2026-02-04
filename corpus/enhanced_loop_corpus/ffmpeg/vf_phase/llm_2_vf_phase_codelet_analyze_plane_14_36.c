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
    // Variant 1: Consecutive memory access with unrolled stride of 2
    uint16_t *n_end = nptr + w - 1;  // Adjust for unrolling by 2
    for (rend = n_end; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        // First element in unrolled pair
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t1 * t1;
        t1 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        bdif += t1 * t1;

        // Second element in unrolled pair
        t2 = ((nptr[1] - optr[1 + os]) << 2) + nptr[(ns) << 1 + 1] - optr[1 - os];
        tdif += t2 * t2;
        t2 = ((optr[1] - nptr[1 + ns]) << 2) + optr[(os) << 1 + 1] - nptr[1 - ns];
        bdif += t2 * t2;
    }

    // Handle leftover element if w is odd
    if (nptr <= n_end + 1) {
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        bdif += t * t;
    }
}
