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
int stride = ns << 1;
for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
    if (nptr + 1 >= rend) break;
    int t1 = ((*(nptr) - nptr[ns]) << 2) + nptr[stride] - nptr[-ns];
    pdif += t1 * t1;
    int t2 = ((*(optr) - optr[os]) << 2) + optr[(os)<<1] - optr[-os];
    tdif += t2 * t2;
    int t3 = ((*(optr) - nptr[ns]) << 2) + optr[(os)<<1] - nptr[-ns];
    bdif += t3 * t3;

    t1 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[stride] - (nptr+1)[-ns];
    pdif += t1 * t1;
    t2 = ((*(optr+1) - (optr+1)[os]) << 2) + (optr+1)[(os)<<1] - (optr+1)[-os];
    tdif += t2 * t2;
    t3 = ((*(optr+1) - (nptr+1)[ns]) << 2) + (optr+1)[(os)<<1] - (nptr+1)[-ns];
    bdif += t3 * t3;
}
}
