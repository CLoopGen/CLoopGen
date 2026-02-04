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
        int64_t diff1, diff2;

        diff1 = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        diff2 = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];

        if ((diff1 & 1) && (diff2 > 0)) {
            pdif += diff1 * diff1;
            tdif += diff2 * diff2;
        } else {
            pdif += (diff1 + 1) * (diff1 + 1);
            tdif += (diff2 + 1) * (diff2 + 1);
        }
    }
}
