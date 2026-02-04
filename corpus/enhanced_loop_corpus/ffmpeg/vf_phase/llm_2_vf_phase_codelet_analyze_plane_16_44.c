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
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with unrolled stride-2 pattern
    // Arrays are accessed in a strided manner with manual unrolling to improve spatial locality
    uint16_t *nptr_end = nptr + w - 1;  // Adjust for unrolling (process two elements per iteration)
    
    for (rend = nptr + w; nptr < nptr_end; nptr += 2, optr += 2) {
        int64_t t1, t2;

        // First element
        t1 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t1 * t1;
        t1 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        bdif += t1 * t1;

        // Second element
        t2 = ((nptr[1] - optr[1 + os]) << 2) + nptr[((ns) << 1) + 1] - optr[1 - os];
        tdif += t2 * t2;
        t2 = ((optr[1] - nptr[1 + ns]) << 2) + optr[((os) << 1) + 1] - nptr[1 - ns];
        bdif += t2 * t2;
    }

    // Handle remaining element if w is odd
    if (nptr < rend) {
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        bdif += t * t;
    }
}
