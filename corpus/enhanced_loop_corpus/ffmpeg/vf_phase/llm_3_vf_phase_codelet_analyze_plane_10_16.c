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
    // Variant 2: Consecutive Forward Access with Local Blocking (unrolled by 2)
    uint16_t *nend = nptr + (w & ~1);  // Round down to even index for safe unrolling

    for (rend = nend; nptr < rend; nptr += 2, optr += 2) {
        // First element in unroll
        pdif += ((t) = ((nptr[0] - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-ns], (t) * (t));
        tdif += ((t) = ((nptr[0] - optr[os]) << 2) + nptr[(ns)<<1] - optr[-os], (t) * (t));

        // Second element in unroll
        pdif += ((t) = ((nptr[1] - (nptr+1)[ns]) << 2) + (nptr+1)[(ns)<<1] - (nptr+1)[-ns], (t) * (t));
        tdif += ((t) = ((nptr[1] - (optr+1)[os]) << 2) + (nptr+1)[(ns)<<1] - (optr+1)[-os], (t) * (t));
    }

    // Handle leftover element if w is odd
    if (w & 1) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
        nptr++; optr++;
    }
}
