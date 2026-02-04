#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
    if (nptr + 1 >= rend) break;
    int t1, t2;
    pdif += ((t1) = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns) << 1] - nptr[-ns], t1 * t1)
          + ((t2) = ((nptr[1] - nptr[1+ns]) << 2) + nptr[1+(ns<<1)] - nptr[1-ns], t2 * t2);
    tdif += ((t1) = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-os], t1 * t1)
          + ((t2) = ((nptr[1] - optr[1+os]) << 2) + nptr[1+(ns<<1)] - optr[1-os], t2 * t2);
}
}
