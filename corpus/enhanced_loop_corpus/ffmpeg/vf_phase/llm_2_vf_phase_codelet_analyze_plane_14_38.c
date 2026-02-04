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



void loop() {
    // Variant 1: Consecutive Memory Access with Unrolling (factor of 2)
    // Arrays are accessed in consecutive pairs to improve spatial locality and enable better vectorization.
    uint16_t *nptr_end = nptr + w - 1;  // Adjust for unrolling by 2
    uint16_t *rend_adj = nptr + w;

    for (rend = rend_adj; nptr < nptr_end; nptr += 2, optr += 2) {
        // First element in the pair
        int t1_n = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t1_n * t1_n;

        int t1_o = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t1_o * t1_o;

        int t1_b = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        bdif += t1_b * t1_b;

        // Second element in the pair
        int t2_n = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns) << 1] - (nptr+1)[-ns];
        pdif += t2_n * t2_n;

        int t2_o = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns) << 1] - (optr+1)[-os];
        tdif += t2_o * t2_o;

        int t2_b = ((*(optr+1) - (nptr+1)[ns]) << 2) + (optr+1)[(os) << 1] - (nptr+1)[-ns];
        bdif += t2_b * t2_b;
    }

    // Handle remaining element if w is odd
    if (nptr < rend) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t * t;

        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t * t;

        t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns];
        bdif += t * t;

        nptr++;
        optr++;
    }
}
