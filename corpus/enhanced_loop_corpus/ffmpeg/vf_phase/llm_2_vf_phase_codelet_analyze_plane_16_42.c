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
for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
    if (nptr + ns < rend && nptr - ns >= nptr - (w % ns)) {
        pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[ns << 1] - (nptr)[-ns], (t) * (t));
    }
    if (optr + os < optr + w && nptr - ns >= nptr - (w % ns)) {
        bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[os << 1] - (nptr)[-ns], (t) * (t));
    }
}
}
