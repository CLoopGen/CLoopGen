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
int stride = 2;
for (rend = nptr + w; nptr < rend; nptr += stride, optr += stride) {
    if (nptr + 1 >= rend) break;
    int64_t diff1_n = (nptr)[0] - optr[os];
    int64_t diff2_n = (nptr)[ns << 1] - optr[-os];
    int64_t temp_n = (diff1_n << 2) + diff2_n;
    bdif += temp_n * temp_n;

    int64_t diff1_o = optr[0] - nptr[ns];
    int64_t diff2_o = optr[os << 1] - nptr[-ns];
    int64_t temp_o = (diff1_o << 2) + diff2_o;
    tdif += temp_o * temp_o;
}
}
