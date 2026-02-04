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
uint16_t *n_indexed[4], *o_indexed[4];
int step = 4;
for (rend = nptr + w; nptr <= rend - step; nptr += step, optr += step) {
    n_indexed[0] = nptr;           o_indexed[0] = optr;
    n_indexed[1] = nptr + ns;      o_indexed[1] = optr + os;
    n_indexed[2] = nptr + (ns<<1); o_indexed[2] = optr + (os<<1);
    n_indexed[3] = nptr - ns;

    pdif += ((t) = ((*n_indexed[0] - *n_indexed[1]) << 2) + *n_indexed[2] - *n_indexed[3], (t) * (t));
    bdif += ((t) = ((*o_indexed[0] - *n_indexed[1]) << 2) + *o_indexed[2] - *n_indexed[3], (t) * (t));
}
}
