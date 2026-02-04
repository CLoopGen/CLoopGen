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
        int64_t ndiff = *(nptr) - (nptr)[ns];
        int64_t odiff = *(nptr) - (optr)[os];
        pdif += ((t) = (ndiff << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], (t) * (t));
        bdif += ((t) = (odiff << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
    }
}
