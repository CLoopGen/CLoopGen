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
    int64_t diff1_n = (*(nptr) - (optr)[os]) << 2;
    int64_t diff2_n = (nptr)[(ns) << 1] - (optr)[-(os)];
    int64_t val_n = diff1_n + diff2_n;
    bdif += val_n * val_n;

    int64_t diff1_o = (*(optr) - (nptr)[ns]) << 2;
    int64_t diff2_o = (optr)[(os) << 1] - (nptr)[-(ns)];
    int64_t val_o = diff1_o + diff2_o;
    tdif += val_o * val_o;

    int64_t diff1_n2 = (*(nptr+1) - (optr+1)[os]) << 2;
    int64_t diff2_n2 = (nptr+1)[(ns) << 1] - (optr+1)[-(os)];
    int64_t val_n2 = diff1_n2 + diff2_n2;
    bdif += val_n2 * val_n2;

    int64_t diff1_o2 = (*(optr+1) - (nptr+1)[ns]) << 2;
    int64_t diff2_o2 = (optr+1)[(os) << 1] - (nptr+1)[-(ns)];
    int64_t val_o2 = diff1_o2 + diff2_o2;
    tdif += val_o2 * val_o2;
}
}
