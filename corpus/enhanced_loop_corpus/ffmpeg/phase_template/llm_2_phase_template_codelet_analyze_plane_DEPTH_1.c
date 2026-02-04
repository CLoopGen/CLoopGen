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
    pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)] , (t) * (t));
    tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)] , (t) * (t));
    pdif += ((t) = (((nptr)[1] - (nptr)[ns+1]) << 2) + (nptr)[(ns)<<1 + 1] - (nptr)[-(ns)+1] , (t) * (t));
    tdif += ((t) = (((optr)[1] - (nptr)[ns+1]) << 2) + (optr)[(os)<<1 + 1] - (nptr)[-(ns)+1] , (t) * (t));
}
}
