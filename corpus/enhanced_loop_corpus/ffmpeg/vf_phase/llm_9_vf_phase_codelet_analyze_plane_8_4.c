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
extern int tdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
    tdif += ((t) = (*(nptr) - optr[os]) + (nptr[(ns) << 1] - optr[-os]), (t) * (t));
    bdif += ((t) = (*(optr) - nptr[ns]) + (optr[(os) << 1] - nptr[-ns]), (t) * (t));
}
}
