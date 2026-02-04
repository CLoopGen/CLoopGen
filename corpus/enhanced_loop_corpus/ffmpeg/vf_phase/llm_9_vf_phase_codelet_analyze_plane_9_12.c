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
for (rend = nptr + (w >> 1); nptr < rend; nptr++, optr++) {
    int64_t t_local = (*(nptr) - optr[os]) + (nptr)[(ns) << 1] - optr[-(os)];
    tdif += t_local * t_local;
    bdif += ((t) = ((*(optr) - nptr[ns]) + (optr)[(os) << 1]), (t) * (t));
}
}
