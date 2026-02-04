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
    // Variant 2: Strided memory access — process every 2nd element first, then the others
    // This changes access pattern to improve cache behavior or enable vectorization
    ptrdiff_t stride = 2;
    for (ptrdiff_t phase = 0; phase < stride; phase++) {
        uint16_t *nstart = nptr + phase;
        uint16_t *ostart = optr + phase;
        rend = nptr + w;
        for (uint16_t *nptr_temp = nstart, *optr_temp = ostart;
             nptr_temp < rend;
             nptr_temp += stride, optr_temp += stride) {
            t = ((*nptr_temp - nptr_temp[ns]) << 2) + nptr_temp[(ns) << 1] - nptr_temp[-(ns)];
            pdif += t * t;
            t = ((*nptr_temp - optr_temp[os]) << 2) + nptr_temp[(ns) << 1] - optr_temp[-(os)];
            bdif += t * t;
        }
    }
    // Update global nptr and optr to reflect full traversal
    nptr += w;
    optr += w;
}
