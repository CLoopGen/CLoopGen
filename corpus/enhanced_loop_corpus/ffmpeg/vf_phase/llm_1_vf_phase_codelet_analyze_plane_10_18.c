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
    for (int k = 0; k < 2; k++) {
        uint16_t *local_nptr = nptr;
        uint16_t *local_optr = optr;
        rend = local_nptr + w;
        if (k == 0) {
            for (; local_nptr < rend; local_nptr++, local_optr++) {
                pdif += ((t) = ((*(local_nptr) - (local_nptr)[ns]) << 2) + (local_nptr)[(ns) << 1] - (local_nptr)[-(ns)], (t) * (t));
            }
        } else {
            for (; local_nptr < rend; local_nptr++, local_optr++) {
                bdif += ((t) = ((*(local_optr) - (local_nptr)[ns]) << 2) + (local_optr)[(os) << 1] - (local_nptr)[-(ns)], (t) * (t));
            }
        }
    }
}
