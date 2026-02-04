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



void loop() {
    // Variant 1: Consecutive memory access with unrolled stride of 2
    uint16_t *nend = nptr + w - 1;  // Adjust for unrolling by 2
    for (rend = nend; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        // First element in unrolled pair
        pdif += ((t1) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)], (int64_t)t1 * t1);
        bdif += ((t1) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)], (int64_t)t1 * t1);

        // Second element in unrolled pair
        pdif += ((t2) = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns) << 1] - (nptr+1)[-(ns)], (int64_t)t2 * t2);
        bdif += ((t2) = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns) << 1] - (optr+1)[-(os)], (int64_t)t2 * t2);
    }

    // Handle leftover element if w is odd
    if (nptr <= nptr + w - 1) {
        nptr = nptr + w - 1;
        optr = optr + w - 1;
        pdif += ((t) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)], (int64_t)t * t);
        bdif += ((t) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)], (int64_t)t * t);
    }
}
