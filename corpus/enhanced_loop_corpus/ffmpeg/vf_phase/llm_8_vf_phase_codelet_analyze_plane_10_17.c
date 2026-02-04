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
        int64_t t1, t2;
        pdif += ((t1) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], t1 * t1);
        pdif += ((t2) = (((nptr)[1] - (nptr)[ns+1]) << 2) + (nptr)[(ns) << 1 | 1] - (nptr)[-(ns)+1], t2 * t2);
        tdif += ((t1) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], t1 * t1);
        tdif += ((t2) = (((optr)[1] - (nptr)[ns+1]) << 2) + (optr)[(os) << 1 | 1] - (nptr)[-(ns)+1], t2 * t2);
    }
}
