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



void loop(){
    // Variant 2: Strided memory access with stride equal to 'ns' for both arrays
    // Instead of unit increment, step by a fixed stride related to ns, simulating a non-unit strided traversal
    int stride = (ns > 1) ? ns : 1;
    uint16_t *stride_nptr = nptr;
    uint16_t *stride_optr = optr;
    uint16_t *limit = nptr + w;

    for (rend = limit; stride_nptr < limit; stride_nptr += stride, stride_optr += stride) {
        // Ensure that all index accesses remain within bounds using conditional checks
        if (stride_nptr + ns < limit && stride_nptr - ns >= nptr && 
            stride_optr + os < optr + w && stride_optr - os >= optr) {

            t = ((*(stride_nptr) - stride_nptr[ns]) << 2) + stride_nptr[(ns) << 1] - stride_nptr[-(ns)];
            pdif += t * t;

            t = ((*(stride_optr) - stride_nptr[ns]) << 2) + stride_optr[(os) << 1] - stride_nptr[-(ns)];
            bdif += t * t;
        }
    }

    // Final cleanup pass for any trailing elements not covered by strided access
    for (; nptr < rend; nptr++, optr++) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-(ns)];
        pdif += t * t;
        t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        bdif += t * t;
    }
}
