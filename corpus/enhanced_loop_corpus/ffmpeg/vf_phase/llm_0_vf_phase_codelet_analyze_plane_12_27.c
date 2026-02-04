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
        int64_t t1, t2;
        pdif += ((t1) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], t1 * t1);
        bdif += ((t2) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], t2 * t2);
    }
}
