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
for (rend = nptr + (w >> 1); nptr < rend; nptr++, optr++) {
    int64_t diff_n = (*(nptr) - (nptr)[ns]);
    int64_t diff_o = (*(optr) - (nptr)[ns]);
    pdif += (diff_n << 1) * (diff_n << 1);
    bdif += (diff_o << 1) * (diff_o << 1);
}
}
