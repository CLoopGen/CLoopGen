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
    // Variant 2: Strided memory access with stride equal to 4
    // Instead of sequential access, traverse arrays with a fixed stride
    const int stride = 4;
    uint16_t *strided_rend = nptr + w;
    for (int i = 0; nptr + i < strided_rend; i += stride) {
        uint16_t *nptr_i = nptr + i;
        uint16_t *optr_i = optr + i;

        // Ensure indices used in stencil accesses are within bounds
        if (nptr_i + ns < strided_rend && nptr_i - ns >= nptr &&
            optr_i + os < optr + w && optr_i - os >= optr) {

            pdif += ((t) = ((*nptr_i - nptr_i[ns]) << 2) + nptr_i[(ns) << 1] - nptr_i[-ns], (t) * (t));
            bdif += ((t) = ((*nptr_i - optr_i[os]) << 2) + nptr_i[(ns) << 1] - optr_i[-os], (t) * (t));
            tdif += ((t) = ((*optr_i - nptr_i[ns]) << 2) + optr_i[(os) << 1] - nptr_i[-ns], (t) * (t));
        }
    }
    // Update nptr and optr to reflect full traversal (simulate side effect)
    nptr = strided_rend;
    optr = optr + w;
}
