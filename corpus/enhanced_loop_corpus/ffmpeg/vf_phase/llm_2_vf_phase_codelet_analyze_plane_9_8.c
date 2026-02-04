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
    // Variant 1: Consecutive (blocked) memory access with unrolling factor of 2
    // This variant processes two elements at a time, accessing nptr and optr consecutively
    // to improve spatial locality and enable potential vectorization.

    uint16_t *nend = nptr + w;
    uint16_t *oend = optr + w;

    for (; nptr + 1 < nend; nptr += 2, optr += 2) {
        int t1, t2;

        // First element
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t1 * t1;
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t1 * t1;

        // Second element
        t2 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns) << 1] - (nptr+1)[-ns];
        pdif += t2 * t2;
        t2 = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns) << 1] - (optr+1)[-os];
        tdif += t2 * t2;
    }

    // Handle remaining element if width is odd
    if (nptr < nend) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t * t;
        nptr++; optr++;
    }
}
