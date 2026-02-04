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
int half_w = w >> 1;
for (rend = nptr + half_w; nptr < rend; nptr++, optr++) {
    int nidx1 = ns, nidx2 = -ns, s2 = ns << 1;
    int oidx1 = os, oidx2 = -os, os2 = os << 1;
    
    int diff_n = (*nptr - nptr[nidx1]);
    int val_p = (diff_n << 2) + nptr[s2] - nptr[nidx2];
    pdif += val_p * val_p;

    int diff_o = (*nptr - optr[oidx1]);
    int val_t = (diff_o << 2) + nptr[s2] - optr[oidx2];
    tdif += val_t * val_t;

    int diff_b = (*optr - nptr[nidx1]);
    int val_b = (diff_b << 2) + optr[os2] - nptr[nidx2];
    bdif += val_b * val_b;
}
}
