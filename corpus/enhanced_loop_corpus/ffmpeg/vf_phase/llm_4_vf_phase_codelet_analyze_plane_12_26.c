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
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int64_t temp_n = *(nptr) - nptr[ns];
        int64_t temp_n2 = nptr[(ns) << 1] - nptr[-(ns)];
        pdif += ((t = (temp_n << 2) + temp_n2), t * t);

        int64_t temp_o = *optr - nptr[ns];
        int64_t temp_o2 = optr[(os) << 1] - nptr[-(ns)];
        bdif += ((t = (temp_o << 2) + temp_o2), t * t);
    }
}
