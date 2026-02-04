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
    int64_t diff_n = (*(nptr) - optr[os]);
    int64_t term_n = (diff_n << 2) + (nptr)[ns << 1] - optr[-os];
    tdif += term_n * term_n;

    int64_t diff_b = (*(optr) - nptr[ns]);
    int64_t term_b = (diff_b << 2) + (optr)[os << 1] - nptr[-ns];
    bdif += term_b * term_b;

    // Reduced trip count and simplified arithmetic by precomputing sub-expressions
    nptr++; optr++;
    if (nptr >= rend) break;
}
}
