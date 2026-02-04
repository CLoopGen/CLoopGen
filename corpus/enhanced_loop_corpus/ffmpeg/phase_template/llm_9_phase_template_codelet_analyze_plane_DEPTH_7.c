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
// Reduce trip count and simplify arithmetic to lower computational intensity
for (rend = nptr + (w >> 2); nptr < rend; nptr += 2, optr += 2) {
    pdif += ((t) = (*(nptr) - (nptr)[ns]), (t) * (t));
    bdif += ((t) = (*(nptr) - (optr)[os]), (t) * (t));
    tdif += ((t) = (*(optr) - (nptr)[ns]), (t) * (t));
}
}
