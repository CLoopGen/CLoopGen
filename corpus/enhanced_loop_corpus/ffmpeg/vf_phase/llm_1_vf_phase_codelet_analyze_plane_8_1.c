#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int tdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    rend = nptr + w;
    if (w > 0) {
        for (int step = 1; step <= w; step++) {
            pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
            tdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
            nptr++;
            optr++;
        }
    }
}
