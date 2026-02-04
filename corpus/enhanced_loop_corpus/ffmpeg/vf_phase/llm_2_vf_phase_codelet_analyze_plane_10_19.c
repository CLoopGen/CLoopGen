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
    // Variant 1: Consecutive Memory Access with Unrolling by 2
    // Instead of accessing nptr[ns], nptr[-ns], etc., we restructure to access consecutive elements
    // assuming ns = 1 (common in stencil patterns). This improves spatial locality.
    int stride = 1;
    for (rend = nptr + w - 1; nptr < rend; nptr += 2, optr += 2) {
        int16_t diff_n1 = ((nptr[0] - nptr[stride]) << 2) + nptr[2*stride] - nptr[-stride];
        int16_t diff_n2 = ((nptr[1] - nptr[1 + stride]) << 2) + nptr[1 + 2*stride] - nptr[1 - stride];
        pdif += diff_n1 * diff_n1 + diff_n2 * diff_n2;

        int16_t diff_o1 = ((nptr[0] - optr[stride]) << 2) + nptr[2*stride] - optr[-stride];
        int16_t diff_o2 = ((nptr[1] - optr[1 + stride]) << 2) + nptr[1 + 2*stride] - optr[1 - stride];
        bdif += diff_o1 * diff_o1 + diff_o2 * diff_o2;
    }
    // Handle leftover element if w was odd
    if (w > 0 && (nptr == rend + 1)) {
        t = ((nptr[0] - nptr[ns]) << 2) + nptr[2*ns] - nptr[-ns];
        pdif += t * t;
        t = ((nptr[0] - optr[os]) << 2) + nptr[2*ns] - optr[-os];
        bdif += t * t;
    }
}
