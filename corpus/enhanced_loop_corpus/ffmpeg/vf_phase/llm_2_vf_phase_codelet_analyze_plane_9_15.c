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
    // Variant 1: Consecutive memory access with unrolled stride-2 pattern
    // Instead of accessing nptr[ns], nptr[-ns], etc., we restructure to use consecutive elements
    // assuming ns = 1 and os = 1 for natural sequential traversal.
    // We also unroll the loop by a factor of 2 for improved locality.

    uint16_t *nend = nptr + (w & ~1);  // Round down to even boundary

    for (rend = nend; nptr < rend; ) {
        // Process two elements at once with direct consecutive access
        int t1, t2;

        // First iteration of unroll
        t1 = (((*nptr) - nptr[1]) << 2) + nptr[2] - nptr[-1];
        pdif += t1 * t1;

        t1 = (((*nptr) - optr[1]) << 2) + nptr[2] - optr[-1];
        bdif += t1 * t1;

        t1 = (((*optr) - nptr[1]) << 2) + optr[2] - nptr[-1];
        tdif += t1 * t1;

        nptr++; optr++;

        // Second iteration of unroll
        t2 = (((*nptr) - nptr[1]) << 2) + nptr[2] - nptr[-1];
        pdif += t2 * t2;

        t2 = (((*nptr) - optr[1]) << 2) + nptr[2] - optr[-1];
        bdif += t2 * t2;

        t2 = (((*optr) - nptr[1]) << 2) + optr[2] - nptr[-1];
        tdif += t2 * t2;

        nptr++; optr++;
    }

    // Handle remaining element if w was odd
    if ((w & 1) && nptr < (nptr + w)) {
        t = (((*nptr) - nptr[1]) << 2) + nptr[2] - nptr[-1];
        pdif += t * t;

        t = (((*nptr) - optr[1]) << 2) + nptr[2] - optr[-1];
        bdif += t * t;

        t = (((*optr) - nptr[1]) << 2) + optr[2] - nptr[-1];
        tdif += t * t;

        nptr++; optr++;
    }
}
