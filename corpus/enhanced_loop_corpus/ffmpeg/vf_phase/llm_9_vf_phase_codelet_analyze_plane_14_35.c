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
int stride = 2;
for (rend = nptr + (w & ~1); nptr < rend; nptr += stride, optr += stride) {
    int64_t temp1, temp2;
    // First element of unrolled pair
    temp1 = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-ns];
    pdif += temp1 * temp1;
    temp2 = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-os];
    bdif += temp2 * temp2;

    // Second element of unrolled pair
    temp1 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns) << 1] - (nptr+1)[-ns];
    pdif += temp1 * temp1;
    temp2 = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[(ns) << 1] - (optr+1)[-os];
    bdif += temp2 * temp2;
}
// Handle odd-sized w with a scalar cleanup if needed
if (w & 1) {
    pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-ns], (int64_t)t * t);
    bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-os], (int64_t)t * t);
}
}
