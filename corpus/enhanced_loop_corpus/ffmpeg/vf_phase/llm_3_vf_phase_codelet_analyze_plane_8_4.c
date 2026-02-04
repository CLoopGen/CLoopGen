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
    // Variant 2: Strided memory access with step size 4 (SIMD-like pattern)
    int stride = 4;
    uint8_t *nptr_end = nptr + (w & ~(stride - 1));  // Round down to multiple of 4

    for (rend = nptr + w; nptr < nptr_end; nptr += stride, optr += stride) {
        // Process four elements with fixed offsets (strided access)
        for (int i = 0; i < stride; i++) {
            tdif += ((t) = ((nptr[i] - optr[i + os]) << 2) + nptr[i + (ns << 1)] - optr[i - os], (t) * (t));
            bdif += ((t) = ((optr[i] - nptr[i + ns]) << 2) + optr[i + (os << 1)] - nptr[i - ns], (t) * (t));
        }
    }

    // Handle trailing elements
    for (; nptr < rend; nptr++, optr++) {
        tdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
        bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    }
}
