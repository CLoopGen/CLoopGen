#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + (w >> 1); nptr < rend; nptr++, optr++) {
    int t1 = (*(nptr) - (nptr)[ns]) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
    int t2 = (*(optr) - (nptr)[ns]) + (optr)[(os) << 1] - (nptr)[-(ns)];
    pdif += t1 * t1;
    tdif += t2 * t2;
}
}
