#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride-2 pattern
    uint16_t *nptr_end = nptr + w - 1;  // Adjust for unrolling (process pairs)
    while (nptr < nptr_end) {
        // Unroll two iterations with consecutive access
        int t1, t2;
        pdif += (t1 = (((*nptr) - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-ns], t1 * t1);
        pdif += (t2 = (((*(nptr+1)) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns)<<1] - (nptr+1)[-ns], t2 * t2);

        tdif += (t1 = (((*optr) - nptr[ns]) << 2) + optr[(os)<<1] - nptr[-ns], t1 * t1);
        tdif += (t2 = (((*(optr+1)) - (nptr+1)[ns]) << 2) + (optr+1)[(os)<<1] - (nptr+1)[-ns], t2 * t2);

        nptr += 2;
        optr += 2;
    }
    // Handle leftover element
    if (nptr < rend) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)] , (t) * (t));
        tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)] , (t) * (t));
        nptr++;
        optr++;
    }
}
