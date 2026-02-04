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
    if (w <= 0) return;
    int chunk = 1;
    for (rend = nptr + w; nptr < rend; ) {
        uint16_t *inner_nptr = nptr;
        uint16_t *inner_optr = optr;
        uint16_t *inner_rend = (nptr + chunk < rend) ? nptr + chunk : rend;

        for (; inner_nptr < inner_rend; inner_nptr++, inner_optr++) {
            pdif += ((t) = ((*(inner_nptr) - (inner_nptr)[ns]) << 2) + (inner_nptr)[(ns) << 1] - (inner_nptr)[-(ns)], (t) * (t));
            bdif += ((t) = ((*(inner_optr) - (inner_nptr)[ns]) << 2) + (inner_optr)[(os) << 1] - (inner_nptr)[-(ns)], (t) * (t));
        }

        nptr = inner_nptr;
        optr = inner_optr;
        chunk <<= 1;
    }
}
