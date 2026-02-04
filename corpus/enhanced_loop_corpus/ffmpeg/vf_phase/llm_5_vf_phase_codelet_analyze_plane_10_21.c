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
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        if ((nptr - nptr) % 2 == 0) {
            bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
            tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
        } else {
            int64_t diff_n = (*(nptr) - (optr)[os]) + (nptr)[(ns) << 1];
            int64_t diff_o = (*(optr) - (nptr)[ns]) + (optr)[(os) << 1];
            bdif += diff_n * diff_n;
            tdif += diff_o * diff_o;
        }
    }
}
