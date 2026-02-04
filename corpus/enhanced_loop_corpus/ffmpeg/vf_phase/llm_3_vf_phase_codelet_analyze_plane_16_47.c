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
    // Variant 2: Consecutive (unrolled by 2) Memory Access with sequential pattern
    uint16_t *nend = nptr + (w & ~1);  // Align to even index for unrolling
    for (rend = nend; nptr < rend; nptr += 2, optr += 2) {
        // First element in unrolled pair
        pdif += ((t) = ((nptr[0] - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-(ns)], (t) * (t));
        bdif += ((t) = ((nptr[0] - optr[os]) << 2) + nptr[(ns)<<1] - optr[-(os)], (t) * (t));
        tdif += ((t) = ((optr[0] - nptr[ns]) << 2) + optr[(os)<<1] - nptr[-(ns)], (t) * (t));

        // Second element in unrolled pair
        pdif += ((t) = ((nptr[1] - (nptr+1)[ns]) << 2) + (nptr+1)[(ns)<<1] - (nptr+1)[-(ns)], (t) * (t));
        bdif += ((t) = ((nptr[1] - (optr+1)[os]) << 2) + (nptr+1)[(ns)<<1] - (optr+1)[-(os)], (t) * (t));
        tdif += ((t) = ((optr[1] - (nptr+1)[ns]) << 2) + (optr+1)[(os)<<1] - (nptr+1)[-(ns)], (t) * (t));
    }
    // Handle leftover element if w is odd
    if ((w & 1) && nptr < nptr + w) {
        pdif += ((t) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)], (t) * (t));
        bdif += ((t) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)], (t) * (t));
        tdif += ((t) = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)], (t) * (t));
    }
}
