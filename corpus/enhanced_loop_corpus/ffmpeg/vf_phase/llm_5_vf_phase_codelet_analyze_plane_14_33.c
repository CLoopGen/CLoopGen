#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int skip_nptr_update = ((intptr_t)nptr % 2) == 0;
        int skip_optr_update = ((intptr_t)optr % 3) == 0;

        if (!skip_nptr_update) {
            pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        }
        if (!skip_optr_update) {
            tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
        }
    }
}
