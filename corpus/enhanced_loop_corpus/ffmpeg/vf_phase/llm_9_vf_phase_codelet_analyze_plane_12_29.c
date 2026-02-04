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
for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
    int64_t t1 = (*(nptr) - (optr)[os]) << 2;
    int64_t t2 = (nptr)[(ns) << 1] - (optr)[-(os)];
    int64_t sum_b = t1 + t2;
    bdif += sum_b * sum_b;

    int64_t t3 = (*(optr) - (nptr)[ns]) << 2;
    int64_t t4 = (optr)[(os) << 1] - (nptr)[-(ns)];
    int64_t sum_t = t3 + t4;
    tdif += sum_t * sum_t;

    // Additional computational intensity: extra dependency chain
    int64_t extra = (sum_b + sum_t) >> 1;
    extra = (extra * extra) >> 2;
    bdif += extra;
    tdif -= extra;
}
}
