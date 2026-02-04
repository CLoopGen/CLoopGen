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
    // Variant 2: Strided memory access with increasing step size (stride = 4)
    const int stride = 4;
    uint16_t *n_base = nptr;
    uint16_t *o_base = optr;
    int count = 0;
    int full_strides = w / stride;

    for (int s = 0; s < stride; s++) {
        nptr = n_base + s;
        optr = o_base + s;
        for (int i = 0; i < full_strides; i++) {
            tdif += ((t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os]), t * t);
            bdif += ((t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns]), t * t);
            nptr += stride;
            optr += stride;
            count++;
        }
    }

    // Handle remainder elements not covered by striding
    nptr = n_base + count;
    optr = o_base + count;
    rend = nptr + (w - count);
    for (; nptr < rend; nptr++, optr++) {
        tdif += ((t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os]), t * t);
        bdif += ((t = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-ns]), t * t);
    }
}
