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
        int cond1 = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        if (cond1 > 0) {
            pdif += cond1 * cond1;
        }
        int cond2 = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        if (cond2 < 0) {
            tdif += cond2 * cond2;
        }
    }
}
