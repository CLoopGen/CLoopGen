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
    // Variant 1: Strided memory access with increased stride
    // Instead of consecutive access, we now access every 2nd element in nptr and optr
    // This changes spatial locality and reduces total iterations by half
    int stride = 2;
    uint16_t *nend = nptr + (w / stride) * stride; // Adjust end to align with stride
    for (rend = nend; nptr < rend; nptr += stride, optr += stride) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns * stride]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        bdif += ((t) = ((*(optr) - (nptr)[ns * stride]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    }
}
