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
for (rend = nptr + (w >> 2); nptr < rend; nptr += 4, optr += 4) {
    int i;
    for (i = 0; i < 4 && nptr + i < rend; i++) {
        pdif += ((t) = ((*(nptr + i) - (nptr + i)[ns]) << 2) + (nptr + i)[(ns) << 1] - (nptr + i)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(nptr + i) - (optr + i)[os]) << 2) + (nptr + i)[(ns) << 1] - (optr + i)[-(os)], (t) * (t));
        bdif += ((t) = ((*(optr + i) - (nptr + i)[ns]) << 2) + (optr + i)[(os) << 1] - (nptr + i)[-(ns)], (t) * (t));
    }
}
}
