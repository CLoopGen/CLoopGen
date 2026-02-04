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
// Reduce trip count and simplify operations to lower computational intensity
int step = 2;
for (rend = nptr + (w / step); nptr < rend; nptr += step, optr += step) {
    // Simplify expressions: remove one term from each difference computation
    pdif += ((t) = (*(nptr) - (nptr)[ns]) << 2, t * t);
    tdif += ((t) = (*(nptr) - (optr)[os]) << 2, t * t);
    bdif += ((t) = (*(optr) - (nptr)[ns]), t * t); // Remove scaling and one term
}
}
