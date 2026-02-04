#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
    int i;
    for (i = 0; i < 4 && (nptr + i) < rend; i++) {
        uint8_t *p = nptr + i;
        uint8_t *q = optr + i;
        pdif += ((t) = ((*p - p[ns]) << 2) + p[(ns) << 1] - p[-ns], (t) * (t));
        tdif += ((t) = ((*p - q[os]) << 2) + p[(ns) << 1] - q[-os], (t) * (t));
        bdif += ((t) = ((*q - p[ns]) << 2) + q[(os) << 1] - p[-ns], (t) * (t));
    }
    nptr += 3; optr += 3;
}
}
