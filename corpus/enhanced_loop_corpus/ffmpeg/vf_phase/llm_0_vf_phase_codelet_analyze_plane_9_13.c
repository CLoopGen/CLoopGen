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
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int64_t t1, t2;
        bdif += (t1 = ((*(nptr) - optr[os]) << 2) + nptr[ns << 1] - optr[-os], t1 * t1);
        tdif += (t1 = ((*(optr) - nptr[ns]) << 2) + optr[os << 1] - nptr[-ns], t1 * t1);
        for (int i = 0; i < 2; i++) {
            // Artificially deepened loop nest with a fixed inner iteration to simulate increased depth
            bdif += (t2 = (i == 0 ? nptr[0] : nptr[1]) - (i == 0 ? optr[os] : optr[os+1]), t2 * t2);
        }
    }
}
