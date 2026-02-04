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
    // Variant 1: Consecutive Memory Access with Unrolling (factor of 2)
    // Arrays are accessed in consecutive order, and loop is unrolled to process two elements per iteration
    // This improves spatial locality and enables better compiler optimization

    uint8_t *nend = nptr + w;
    rend = (nptr + w) - 1; // Adjust for unrolling (process pairs)

    for (; nptr < rend; nptr += 2, optr += 2) {
        // First element
        int t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t1 * t1;
        int t2 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        tdif += t2 * t2;
        int t3 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        bdif += t3 * t3;

        // Second element (consecutive access)
        t1 = ((nptr[1] - nptr[1 + ns]) << 2) + nptr[1 + (ns << 1)] - nptr[1 - ns];
        pdif += t1 * t1;
        t2 = ((nptr[1] - optr[1 + os]) << 2) + nptr[1 + (ns << 1)] - optr[1 - os];
        tdif += t2 * t2;
        t3 = ((optr[1] - nptr[1 + ns]) << 2) + optr[1 + (os << 1)] - nptr[1 - ns];
        bdif += t3 * t3;
    }

    // Handle remaining element if width is odd
    if (nptr < nend) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        tdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        bdif += t * t;
        nptr++; optr++;
    }
}
