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
    const int unroll_factor = 4;
    uint16_t *limit = rend = nptr + (w / unroll_factor) * unroll_factor;

    for (; nptr < limit; nptr += unroll_factor, optr += unroll_factor) {
        // Unrolled accumulation to increase computational intensity
        pdif += (((*(nptr) - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-ns]) *
               (((*(nptr) - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-ns]);
        pdif += (((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns)<<1] - (nptr+1)[-ns]) *
               (((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns)<<1] - (nptr+1)[-ns]);
        pdif += (((*(nptr+2) - (nptr+2)[ns]) << 2) + (nptr+2)[(ns)<<1] - (nptr+2)[-ns]) *
               (((*(nptr+2) - (nptr+2)[ns]) << 2) + (nptr+2)[(ns)<<1] - (nptr+2)[-ns]);
        pdif += (((*(nptr+3) - (nptr+3)[ns]) << 2) + (nptr+3)[(ns)<<1] - (nptr+3)[-ns]) *
               (((*(nptr+3) - (nptr+3)[ns]) << 2) + (nptr+3)[(ns)<<1] - (nptr+3)[-ns]);

        tdif += (((*(nptr) - optr[os]) << 2) + nptr[(ns)<<1] - optr[-os]) *
               (((*(nptr) - optr[os]) << 2) + nptr[(ns)<<1] - optr[-os]);
        tdif += (((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns)<<1] - (optr+1)[-os]) *
               (((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns)<<1] - (optr+1)[-os]);
        tdif += (((*(nptr+2) - (optr+2)[os]) << 2) + (nptr+2)[(ns)<<1] - (optr+2)[-os]) *
               (((*(nptr+2) - (optr+2)[os]) << 2) + (nptr+2)[(ns)<<1] - (optr+2)[-os]);
        tdif += (((*(nptr+3) - (optr+3)[os]) << 2) + (nptr+3)[(ns)<<1] - (optr+3)[-os]) *
               (((*(nptr+3) - (optr+3)[os]) << 2) + (nptr+3)[(ns)<<1] - (optr+3)[-os]);
    }

    // Handle remaining elements
    for (; nptr < rend; nptr++, optr++) {
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t * t;
    }
}
