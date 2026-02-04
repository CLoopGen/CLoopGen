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
    // Variant 1: Consecutive memory access with unrolling by 2 to improve spatial locality
    // Arrays are accessed in a more sequential pattern, reducing cache misses
    uint16_t *nptr_end = nptr + w - 1;
    for (rend = nptr + w; nptr < nptr_end; nptr += 2, optr += 2) {
        int t1, t2;

        // First element
        pdif += (t1 = (((*nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], (int64_t)t1 * t1);
        bdif += (t1 = (((*nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], (int64_t)t1 * t1);
        tdif += (t1 = (((*optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns], (int64_t)t1 * t1);

        // Second element
        pdif += (t2 = (((nptr[1]) - nptr[1 + ns]) << 2) + nptr[1 + (ns << 1)] - nptr[1 - ns], (int64_t)t2 * t2);
        bdif += (t2 = (((nptr[1]) - optr[1 + os]) << 2) + nptr[1 + (ns << 1)] - optr[1 - os], (int64_t)t2 * t2);
        tdif += (t2 = (((optr[1]) - nptr[1 + ns]) << 2) + optr[1 + (os << 1)] - nptr[1 - ns], (int64_t)t2 * t2);
    }

    // Handle remaining element if w is odd
    if (nptr < rend) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)] , (t) * (t));
        bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)] , (t) * (t));
        tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)] , (t) * (t));
        nptr++; optr++;
    }
}
