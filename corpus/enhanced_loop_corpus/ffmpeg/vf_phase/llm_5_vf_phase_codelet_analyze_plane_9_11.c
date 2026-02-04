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
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        if ((nptr - nptr) % 2 == 0) {
            pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
            bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
        } else {
            int64_t diff_n = (*(nptr) - (nptr)[ns]) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
            int64_t diff_o = (*(nptr) - (optr)[os]) + (nptr)[(ns) << 1] - (optr)[-(os)];
            pdif += diff_n * diff_n;
            bdif += diff_o * diff_o;
        }
    }
}
