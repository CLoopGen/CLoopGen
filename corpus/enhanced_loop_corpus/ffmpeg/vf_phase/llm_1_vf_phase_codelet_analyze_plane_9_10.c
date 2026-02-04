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
    for (int outer = 0; outer < w / 2; outer++) {
        uint16_t *nptr_local = nptr + outer * 2;
        uint16_t *optr_local = optr + outer * 2;
        rend = nptr_local + 2;
        for (; nptr_local < rend; nptr_local++, optr_local++) {
            pdif += ((t) = ((*(nptr_local) - nptr_local[ns]) << 2) + nptr_local[(ns) << 1] - nptr_local[-ns], (t) * (t));
            bdif += ((t) = ((*(optr_local) - nptr_local[ns]) << 2) + optr_local[(os) << 1] - nptr_local[-ns], (t) * (t));
        }
    }
    // Handle odd w
    if (w % 2 == 1) {
        pdif += ((t) = ((*(nptr + w - 1) - (nptr + w - 1)[ns]) << 2) + (nptr + w - 1)[(ns) << 1] - (nptr + w - 1)[-ns], (t) * (t));
        bdif += ((t) = ((*(optr + w - 1) - (nptr + w - 1)[ns]) << 2) + (optr + w - 1)[(os) << 1] - (nptr + w - 1)[-ns], (t) * (t));
    }
}
