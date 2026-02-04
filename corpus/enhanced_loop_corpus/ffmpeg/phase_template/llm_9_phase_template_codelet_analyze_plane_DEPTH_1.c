#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
    int64_t term_n = (*(nptr) - (nptr)[ns]);
    int64_t term_o = (*(optr) - (nptr)[ns]);
    pdif += ((t) = ((term_n << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)]) , (t) * (t));
    tdif += ((t) = ((term_o << 2) + (optr)[(os) << 1] - (nptr)[-(ns)]) , (t) * (t));
    // Reduced trip count and simplified expressions via reuse of common subexpressions
}
}
