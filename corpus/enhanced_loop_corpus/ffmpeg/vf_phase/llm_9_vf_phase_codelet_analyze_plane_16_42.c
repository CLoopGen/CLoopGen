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
for (rend = nptr + (w >> 2); nptr < rend; nptr += 4, optr += 4) {
    int64_t t;
    pdif += ((t = ((nptr[0] - nptr[ns]) << 2) + nptr[ns<<1] - nptr[-ns]), t * t);
    bdif += ((t = ((optr[0] - nptr[ns]) << 2) + optr[os<<1] - nptr[-ns]), t * t);

    pdif += ((t = ((nptr[1] - nptr[ns+1]) << 2) + nptr[(ns+1)<<1] - nptr[-(ns+1)]), t * t);
    bdif += ((t = ((optr[1] - nptr[ns+1]) << 2) + optr[(os+1)<<1] - nptr[-(ns+1)]), t * t);

    pdif += ((t = ((nptr[2] - nptr[ns+2]) << 2) + nptr[(ns+2)<<1] - nptr[-(ns+2)]), t * t);
    bdif += ((t = ((optr[2] - nptr[ns+2]) << 2) + optr[(os+2)<<1] - nptr[-(ns+2)]), t * t);

    pdif += ((t = ((nptr[3] - nptr[ns+3]) << 2) + nptr[(ns+3)<<1] - nptr[-(ns+3)]), t * t);
    bdif += ((t = ((optr[3] - nptr[ns+3]) << 2) + optr[(os+3)<<1] - nptr[-(ns+3)]), t * t);
}
}
