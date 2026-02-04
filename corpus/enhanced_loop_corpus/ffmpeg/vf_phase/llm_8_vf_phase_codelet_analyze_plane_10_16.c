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
    for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
        if (nptr + 1 >= rend) break;
        int64_t diff1_n, diff2_n, diff1_o, diff2_o;

        // First element
        t = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns];
        pdif += t * t;
        t = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os];
        tdif += t * t;

        // Second element
        t = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns) << 1] - (nptr+1)[-ns];
        pdif += t * t;
        t = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns) << 1] - (optr+1)[-os];
        tdif += t * t;
    }
}
