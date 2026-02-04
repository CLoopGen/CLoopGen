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
for (rend = nptr + (w & ~7); nptr < rend; nptr += 8, optr += 8) {
    for (int i = 0; i < 8; ++i) {
        pdif += ((t) = ((nptr[i]) - (nptr)[ns + i]) << 2) + (nptr)[(ns << 1) + i] - (nptr)[-ns + i];
        pdif += t * t;
        bdif += ((t) = ((nptr[i]) - (optr)[os + i]) << 2) + (nptr)[(ns << 1) + i] - (optr)[-os + i];
        bdif += t * t;
    }
}
}
