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
    // Variant 1: Strided Memory Access (stride of 2)
    for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
        // Handle boundary: ensure we don't go out of bounds when accessing ns and os offsets
        if (nptr + ns >= rend || nptr - ns < nptr - (w % 2 ? w/2 + 1 : w/2)) continue;
        if (optr + os >= rend || optr - os < optr - (w % 2 ? w/2 + 1 : w/2)) continue;

        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
    }
}
