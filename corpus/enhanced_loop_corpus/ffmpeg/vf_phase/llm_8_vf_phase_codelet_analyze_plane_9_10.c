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
    if (nptr + ns < rend && nptr - ns >= nptr - w) {
        int64_t t1 = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[ns << 1] - (nptr)[-ns];
        pdif += t1 * t1;
        int64_t t2 = ((*(optr) - (nptr)[ns]) << 2) + (optr)[os << 1] - (nptr)[-ns];
        bdif += t2 * t2;

        if (nptr + 1 + ns < rend && nptr + 1 - ns >= nptr - w) {
            int64_t t3 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[ns << 1] - (nptr+1)[-ns];
            pdif += t3 * t3;
            int64_t t4 = ((*(optr+1) - (nptr+1)[ns]) << 2) + (optr+1)[os << 1] - (nptr+1)[-ns];
            bdif += t4 * t4;
        }
    }
}
}
