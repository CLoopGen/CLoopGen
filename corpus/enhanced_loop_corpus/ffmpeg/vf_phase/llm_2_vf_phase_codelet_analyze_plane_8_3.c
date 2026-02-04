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
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Arrays are accessed in consecutive pairs to improve spatial locality
    uint8_t *nptr_end = (nptr + w) - 1; // Adjust for pair access
    for (rend = nptr_end; nptr < rend; nptr += 2, optr += 2) {
        int t1, t2;

        // First element
        t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t1 * t1;
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        bdif += t1 * t1;

        // Second element
        t2 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns) << 1] - (nptr+1)[-ns];
        pdif += t2 * t2;
        t2 = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns) << 1] - (optr+1)[-os];
        bdif += t2 * t2;
    }

    // Handle remaining element if w is odd
    if (nptr == nptr_end + 1) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        bdif += t * t;
        nptr++;
        optr++;
    }
}
