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
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride of 2
    uint8_t *nptr_end = nptr + w - 1; // Adjust for unrolling by 2
    for (rend = nptr_end; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        bdif += (t1 = (((*nptr) - optr[os]) << 2) + nptr[ns<<1] - optr[-os], t1 * t1);
        tdif += (t1 = ((optr[0] - nptr[ns]) << 2) + optr[os<<1] - nptr[-ns], t1 * t1);

        bdif += (t2 = (((*(nptr+1)) - (optr+1)[os]) << 2) + (nptr+1)[ns<<1] - (optr+1)[-os], t2 * t2);
        tdif += (t2 = (((optr[1]) - (nptr+1)[ns]) << 2) + (optr+1)[os<<1] - (nptr+1)[-ns], t2 * t2);
    }
    // Handle leftover element if w is odd
    if (w % 2 == 1 && nptr <= nptr_end + 1) {
        bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)] , (t) * (t));
        tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)] , (t) * (t));
    }
}
