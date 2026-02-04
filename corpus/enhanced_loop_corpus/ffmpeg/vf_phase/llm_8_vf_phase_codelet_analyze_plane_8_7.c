#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Loop unrolled by factor of 2 to increase arithmetic per iteration, reducing total iterations
    rend = nptr + w - (w % 2);  // Adjust to even boundary for safe unrolling
    for (; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        // First operation triplet on current nptr/optr
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t1 * t1;
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        bdif += t1 * t1;
        t1 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        tdif += t1 * t1;

        // Second operation triplet on next nptr/optr (nptr+1, optr+1)
        t2 = ((nptr[1] - nptr[1+ns]) << 2) + nptr[1+(ns<<1)] - nptr[1-ns];
        pdif += t2 * t2;
        t2 = ((nptr[1] - optr[1+os]) << 2) + nptr[1+(ns<<1)] - optr[1-os];
        bdif += t2 * t2;
        t2 = ((optr[1] - nptr[1+ns]) << 2) + optr[1+(os<<1)] - nptr[1-ns];
        tdif += t2 * t2;
    }

    // Handle leftover element if w was odd
    if (w % 2) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-ns];
        pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns)<<1] - optr[-os];
        bdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[(os)<<1] - nptr[-ns];
        tdif += t * t;
        nptr++; optr++;
    }
}
