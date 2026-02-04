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
// Reduce trip count and computational load by processing every second element
for (rend = nptr + (w >> 1); nptr < rend; nptr += 2, optr += 2) {
    // Simplify expressions: remove one term from each difference computation
    pdif += ((t) = (*(nptr) - (nptr)[ns]) << 2, t * t);
    bdif += ((t) = (*(nptr) - (optr)[os]), t * t);
    tdif += ((t) = (*(optr) - (nptr)[ns]), t * t);
}
}
