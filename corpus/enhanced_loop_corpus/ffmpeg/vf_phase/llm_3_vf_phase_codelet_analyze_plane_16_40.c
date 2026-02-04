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
    // Variant 2: Strided memory access — process every 2nd element in a forward pass, then the odd positions in a second loop
    // First pass: even indices with stride 2
    uint16_t *rend_even = nptr + (w & ~1);  // Round down to even boundary
    for (; nptr < rend_even; nptr += 2, optr += 2) {
        pdif += ((t) = (((*nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], (t) * (t));
        tdif += ((t) = (((*nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], (t) * (t));
    }

    // Second pass: handle remaining odd element if w is odd
    if (w & 1) {
        pdif += ((t) = (((*nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], (t) * (t));
        tdif += ((t) = (((*nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], (t) * (t));
        nptr++;
        optr++;
    }
}
