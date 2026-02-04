#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
    int t1 = (*(nptr) - (nptr)[ns]) << 2;
    int t2 = (nptr)[(ns) << 1] - (nptr)[-(ns)];
    pdif += (t1 + t2) * (t1 + t2);
    
    int t3 = (*(optr) - (nptr)[ns]) << 2;
    int t4 = (optr)[(os) << 1] - (nptr)[-(ns)];
    bdif += (t3 + t4) * (t3 + t4);
}
}
