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



void loop(){
    // Variant 1: Consecutive memory access with unrolling factor of 2
    // Access pattern changed to process two elements per iteration consecutively
    uint16_t *nend = nptr + w - 1;  // Adjust to avoid out-of-bounds for unrolling
    for (rend = nptr + w; nptr < nend; nptr += 2, optr += 2) {
        // First element in the pair
        pdif += ((t) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], (t) * (t));
        bdif += ((t) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], (t) * (t));
        tdif += ((t) = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns], (t) * (t));

        // Second element in the pair
        pdif += ((t) = ((nptr[1] - (nptr[1 + ns])) << 2) + nptr[1 + (ns << 1)] - nptr[1 - ns], (t) * (t));
        bdif += ((t) = ((nptr[1] - optr[1 + os]) << 2) + nptr[1 + (ns << 1)] - optr[1 - os], (t) * (t));
        tdif += ((t) = ((optr[1] - nptr[1 + ns]) << 2) + optr[1 + (os << 1)] - nptr[1 - ns], (t) * (t));
    }
    // Handle remaining element if width is odd
    if (nptr < rend) {
        pdif += ((t) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], (t) * (t));
        bdif += ((t) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], (t) * (t));
        tdif += ((t) = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns], (t) * (t));
        nptr++;
        optr++;
    }
}
