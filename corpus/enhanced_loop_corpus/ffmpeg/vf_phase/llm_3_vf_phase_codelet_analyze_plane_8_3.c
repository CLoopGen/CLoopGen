#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with stride 4
    // Access every 4th element first, then proceed with next sub-sequence
    const int stride = 4;
    uint8_t *base_nptr = nptr;
    uint8_t *base_optr = optr;
    int i;

    for (i = 0; i < stride; i++) {
        nptr = base_nptr + i;
        optr = base_optr + i;
        rend = base_nptr + w;

        for (; nptr < rend; nptr += stride, optr += stride) {
            t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
            pdif += t * t;
            t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
            bdif += t * t;
        }
    }

    // Restore final pointer positions (optional, for consistency with original semantics)
    nptr = base_nptr + w;
    optr = base_optr + w;
}
