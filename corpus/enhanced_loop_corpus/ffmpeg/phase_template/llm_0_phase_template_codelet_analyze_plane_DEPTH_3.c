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
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int64_t temp1 = (*(nptr) - nptr[ns]) << 2;
        temp1 += nptr[ns << 1] - nptr[-ns];
        pdif += temp1 * temp1;

        int64_t temp2 = (*(nptr) - optr[os]) << 2;
        temp2 += nptr[ns << 1] - optr[-os];
        bdif += temp2 * temp2;
    }
}
