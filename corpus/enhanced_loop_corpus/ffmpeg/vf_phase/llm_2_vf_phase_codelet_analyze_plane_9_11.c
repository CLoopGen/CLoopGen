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
    // Variant 1: Consecutive memory access with unrolling by 2 to modify access pattern
    uint16_t *nend = nptr + w - 1;
    for (rend = nptr + w; nptr < nend; nptr += 2, optr += 2) {
        int t1, t2;
        // First element
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t1 * t1;
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        bdif += t1 * t1;
        // Second element
        t2 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns) << 1] - (nptr+1)[-(ns)];
        pdif += t2 * t2;
        t2 = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns) << 1] - (optr+1)[-(os)];
        bdif += t2 * t2;
    }
    // Handle last element if w is odd
    if (nptr < rend) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        bdif += t * t;
        nptr++;
        optr++;
    }
}
