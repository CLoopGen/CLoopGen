#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int tdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int inner_count = 2;
        for (int i = 0; i < inner_count; i++) {
            bdif += ((t) = ((*(nptr + i*ns) - (optr)[i*os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
            tdif += ((t) = ((*(optr + i*os) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
        }
    }
}
