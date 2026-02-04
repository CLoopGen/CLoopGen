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
    // Variant 2: Strided memory access (stride of 4) for improved cache behavior or vectorization
    const int stride = 4;
    uint16_t *nptr_end = nptr + w - (w % stride);  // Align to stride boundary

    for (; nptr < nptr_end; nptr += stride, optr += stride) {
        // Process four elements per loop iteration with fixed stride
        for (int i = 0; i < stride; i++) {
            pdif += (t = ((nptr[i]) - nptr[i + ns]) << 2) + nptr[i + (ns<<1)] - nptr[i - ns], t * t;
            tdif += (t = ((optr[i]) - nptr[i + ns]) << 2) + optr[i + (os<<1)] - nptr[i - ns], t * t;
        }
    }

    // Handle remaining elements
    for (; nptr < rend; nptr++, optr++) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    }
}
