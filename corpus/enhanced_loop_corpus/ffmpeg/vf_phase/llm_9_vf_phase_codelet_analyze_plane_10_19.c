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
for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
    int64_t t1 = (*(nptr) - nptr[ns]) + (nptr)[(ns) << 1];
    int64_t t2 = (*(nptr) - optr[os]) + (nptr)[(ns) << 1];
    pdif += t1 * t1;
    bdif += t2 * t2;
    nptr++; optr++;
    if (nptr >= rend) break;
    t1 = (*(nptr) - nptr[ns]) + (nptr)[(ns) << 1];
    t2 = (*(nptr) - optr[os]) + (nptr)[(ns) << 1];
    pdif += t1 * t1;
    bdif += t2 * t2;
}
}
