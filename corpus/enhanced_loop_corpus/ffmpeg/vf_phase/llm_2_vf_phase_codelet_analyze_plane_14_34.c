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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Arrays are accessed in a consecutive pattern by precomputing base offsets and stepping through pairs
    uint16_t *nptr_end = nptr + w - (w % 2);  // Align to even boundary for unrolling
    for (rend = nptr_end; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        // First element
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t1 * t1;
        t1 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        bdif += t1 * t1;

        // Second element
        t2 = ((nptr[1] - nptr[1 + ns]) << 2) + nptr[(1 + (ns) << 1)] - nptr[1 - ns];
        pdif += t2 * t2;
        t2 = ((optr[1] - nptr[1 + ns]) << 2) + optr[1 + (os) << 1] - nptr[1 - ns];
        bdif += t2 * t2;
    }

    // Handle remaining element if w is odd
    if (w % 2 && nptr < nptr + w) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        bdif += t * t;
    }
}
