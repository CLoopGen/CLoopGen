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
    if (w > 0) {
        rend = nptr + w;
        for (int i = 0; i < 1; i++) {
            for (; nptr < rend; nptr++, optr++) {
                bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)] , (t) * (t));
                tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)] , (t) * (t));
            }
        }
    }
}
