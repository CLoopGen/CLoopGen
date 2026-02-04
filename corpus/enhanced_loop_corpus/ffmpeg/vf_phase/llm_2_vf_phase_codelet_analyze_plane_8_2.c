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
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Arrays are accessed in a consecutive manner by prefetching two elements per iteration
    uint8_t *nptr_end = nptr + w - 1;
    for (rend = nptr + w; nptr < nptr_end; nptr += 2, optr += 2) {
        int t1, t2;

        // First element
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t1 * t1;
        t2 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        bdif += t2 * t2;

        // Second element
        t1 = ((nptr[1] - nptr[1 + ns]) << 2) + nptr[1 + (ns << 1)] - nptr[1 - ns];
        pdif += t1 * t1;
        t2 = ((optr[1] - nptr[1 + ns]) << 2) + optr[1 + (os << 1)] - nptr[1 - ns];
        bdif += t2 * t2;
    }

    // Handle remaining element if width is odd
    if (nptr < rend) {
        t = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        pdif += t * t;
        t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        bdif += t * t;
    }
}
