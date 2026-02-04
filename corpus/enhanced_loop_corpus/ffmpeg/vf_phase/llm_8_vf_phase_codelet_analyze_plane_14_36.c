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
for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
    if (nptr + 1 >= rend) break;
    int64_t t1_n = (*(nptr) - optr[os]) << 2;
    int64_t t1_n_next = ((nptr)[ns] - (optr)[os]) << 2;
    tdif += (t1_n + (nptr)[ns<<1] - optr[-os]) * (t1_n + (nptr)[ns<<1] - optr[-os]);
    tdif += (t1_n_next + (nptr+1)[ns<<1] - (optr+1)[-os]) * (t1_n_next + (nptr+1)[ns<<1] - (optr+1)[-os]);

    int64_t t1_b = (*(optr) - nptr[ns]) << 2;
    int64_t t1_b_next = ((optr)[ns] - (nptr)[ns]) << 2;
    bdif += (t1_b + (optr)[os<<1] - nptr[-ns]) * (t1_b + (optr)[os<<1] - nptr[-ns]);
    bdif += (t1_b_next + (optr+1)[os<<1] - (nptr+1)[-ns]) * (t1_b_next + (optr+1)[os<<1] - (nptr+1)[-ns]);
}
}
