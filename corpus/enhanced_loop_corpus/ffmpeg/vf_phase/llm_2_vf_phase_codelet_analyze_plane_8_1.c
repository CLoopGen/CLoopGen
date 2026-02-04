#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Unrolling by 2
    // Arrays are accessed in a consecutive pattern, processing two elements per iteration to improve spatial locality.
    rend = nptr + (w & ~1);  // Round down to even boundary
    for (; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;
        pdif += (t1 = ((nptr[0] - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-ns], t1 * t1)
               + (t2 = ((nptr[1] - nptr[1+ns]) << 2) + nptr[1+(ns<<1)] - nptr[1-ns], t2 * t2);
        tdif += (t1 = ((optr[0] - nptr[ns]) << 2) + optr[(os)<<1] - nptr[-ns], t1 * t1)
               + (t2 = ((optr[1] - nptr[1+ns]) << 2) + optr[1+(os<<1)] - nptr[1-ns], t2 * t2);
    }
    // Handle remaining element if w is odd
    if ((w & 1) && nptr < nptr + w) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    }
}
