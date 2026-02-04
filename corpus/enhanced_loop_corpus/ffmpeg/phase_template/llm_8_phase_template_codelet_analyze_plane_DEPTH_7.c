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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + w; nptr < rend; nptr++, optr++) {
    int64_t t1, t2, t3;
    // Increase computational intensity by unrolling and adding more operations
    pdif += ((t1) = ((*(nptr) - (nptr)[ns]) << 3) + ((nptr)[(ns) << 1] - (nptr)[-(ns)]) + (nptr)[ns+1] - (nptr)[1-ns], (t1) * (t1));
    bdif += ((t2) = ((*(nptr) - (optr)[os]) << 3) + ((nptr)[(ns) << 1] - (optr)[-(os)]) + (optr)[os] - (nptr)[ns], (t2) * (t2));
    tdif += ((t3) = ((*(optr) - (nptr)[ns]) << 3) + ((optr)[(os) << 1] - (nptr)[-(ns)]) + (nptr)[0] - (optr)[0], (t3) * (t3));
}
}
