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
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Step
    // Introduce a fixed stride (e.g., 4) to simulate strided memory access pattern,
    // which may model block processing or cache-conscious traversal.
    // This variant accesses elements spaced by a constant stride to reduce pressure on adjacent cache lines.

    const int stride = 4;
    uint16_t *nbase = nptr;
    uint16_t *obase = optr;
    int limit = (w / stride) * stride;  // Round down to nearest multiple of stride

    for (int i = 0; i < limit; i += stride) {
        // Access every 'stride'-th element to create strided pattern
        int nidx = i;
        tdif += ((t) = (((nbase[nidx]) - obase[nidx + os]) << 2) + nbase[nidx + (ns << 1)] - obase[nidx - os], (t) * (t));
        bdif += ((t) = (((obase[nidx]) - nbase[nidx + ns]) << 2) + obase[nidx + (os << 1)] - nbase[nidx - ns], (t) * (t));
    }

    // Finalize with scalar cleanup for remaining elements
    for (int i = limit; i < w; i++) {
        tdif += ((t) = (((nbase[i]) - obase[i + os]) << 2) + nbase[i + (ns << 1)] - obase[i - os], (t) * (t));
        bdif += ((t) = (((obase[i]) - nbase[i + ns]) << 2) + obase[i + (os << 1)] - nbase[i - ns], (t) * (t));
    }
}
