#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Step
    // Instead of unit stride, access memory with a fixed stride (e.g., every 4th element) to simulate different cache behavior.
    const int stride = 4;
    uint8_t *nend = nptr + (w / stride) * stride;  // Adjust bound to multiple of stride

    for (; nptr < nend; nptr += stride, optr += stride) {
        pdif += ((t) = ((nptr[0] - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], (t) * (t));
        tdif += ((t) = ((optr[0] - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns], (t) * (t));
    }

    // Remaining elements processed with original unit stride
    rend = nptr + (w % stride);
    for (; nptr < rend; nptr++, optr++) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    }
}
