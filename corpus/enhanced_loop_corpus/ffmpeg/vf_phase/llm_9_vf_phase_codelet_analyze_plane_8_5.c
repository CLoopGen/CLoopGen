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
    // Variant 2: Reduced computational intensity with halved effective trip count and simplified expressions
    uint8_t *end = nptr + (w >> 1);  // Halve the number of iterations
    for (rend = end; nptr < rend; nptr++, optr++) {
        // Simplify computations: remove one term from each difference expression
        bdif += ((t) = (*(nptr) - (optr)[os]) << 2, (t) * (t));          // Removed diagonal neighbor term
        tdif += ((t) = (*(optr) - (nptr)[ns]) << 2, (t) * (t));          // Removed diagonal neighbor term
    }
}
