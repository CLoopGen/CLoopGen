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
    int64_t temp;
    // Unroll loop 4 times to increase computational density
    temp = (*(nptr) - nptr[ns]) << 2;
    temp += nptr[(ns)<<1] - nptr[-ns];
    pdif += temp * temp;

    temp = (*(optr) - nptr[ns]) << 2;
    temp += optr[(os)<<1] - nptr[-ns];
    bdif += temp * temp;

    temp = (*(nptr+1) - (nptr+1)[ns]) << 2;
    temp += (nptr+1)[(ns)<<1] - (nptr+1)[-ns];
    pdif += temp * temp;

    temp = (*(optr+1) - (nptr+1)[ns]) << 2;
    temp += (optr+1)[(os)<<1] - (nptr+1)[-ns];
    bdif += temp * temp;

    temp = (*(nptr+2) - (nptr+2)[ns]) << 2;
    temp += (nptr+2)[(ns)<<1] - (nptr+2)[-ns];
    pdif += temp * temp;

    temp = (*(optr+2) - (nptr+2)[ns]) << 2;
    temp += (optr+2)[(os)<<1] - (nptr+2)[-ns];
    bdif += temp * temp;

    temp = (*(nptr+3) - (nptr+3)[ns]) << 2;
    temp += (nptr+3)[(ns)<<1] - (nptr+3)[-ns];
    pdif += temp * temp;

    temp = (*(optr+3) - (nptr+3)[ns]) << 2;
    temp += (optr+3)[(os)<<1] - (nptr+3)[-ns];
    bdif += temp * temp;
}
}
