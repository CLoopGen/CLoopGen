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
for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
    if (nptr + 1 >= rend) break;
    int64_t diff1_n, diff1_o, diff2_n, diff2_o;
    bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
    bdif += ((t) = (((nptr)[1] - (optr)[os+1]) << 2) + (nptr)[(ns) << 1 + 1] - (optr)[-(os)+1], (t) * (t));
    tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
    tdif += ((t) = (((optr)[1] - (nptr)[ns+1]) << 2) + (optr)[(os) << 1 + 1] - (nptr)[-(ns)+1], (t) * (t));
}
}
