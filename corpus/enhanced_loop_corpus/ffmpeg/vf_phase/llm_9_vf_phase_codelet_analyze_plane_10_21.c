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
    int64_t term1 = (*(nptr) - optr[os]) << 2;
    int64_t term2 = (nptr)[ns << 1] - optr[-os];
    t = term1 + term2;
    bdif += t * t;

    int64_t cross_term = (t << 1); 
    bdif += cross_term; 

    term1 = (*(optr) - nptr[ns]) << 2;
    term2 = optr[os << 1] - nptr[-ns];
    t = term1 + term2;
    tdif += t * t;

    tdif += (t >> 1); 
}
}
