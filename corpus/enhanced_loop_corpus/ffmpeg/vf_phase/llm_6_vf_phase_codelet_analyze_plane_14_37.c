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
for (rend = nptr + w; nptr < rend; nptr++ , optr++) {
    int64_t temp_n = *(nptr);
    int64_t temp_o = *(optr);
    int64_t diff1 = ((temp_n - optr[os]) << 2) + nptr[ns << 1] - optr[-os];
    int64_t diff2 = ((temp_o - nptr[ns]) << 2) + optr[os << 1] - nptr[-ns];
    bdif += diff1 * diff1;
    tdif += diff2 * diff2;
}
}
