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
    // Variant 1: Consecutive Memory Access (unrolled by 2) with sequential array traversal
    rend = nptr + w;
    for (; nptr < rend - 1; nptr += 2, optr += 2) {
        int64_t t1, t2;

        // Process two elements of nptr consecutively
        t1 = ((nptr[0] - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        t2 = ((nptr[1] - nptr[1 + ns]) << 2) + (nptr[1 + (ns<<1)]) - nptr[1 - ns];
        pdif += t1 * t1 + t2 * t2;

        t1 = ((optr[0] - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        t2 = ((optr[1] - nptr[1 + ns]) << 2) + (optr[1 + (os<<1)]) - nptr[1 - ns];
        bdif += t1 * t1 + t2 * t2;
    }

    // Handle remaining element if width is odd
    if (nptr < rend) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
        nptr++, optr++;
    }
}
