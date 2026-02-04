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
        int64_t temp_pdif = 0;
        int64_t temp_bdif = 0;
        for (int i = 0; i < 2; i++) {
            int t1, t2;
            if (i == 0 && (nptr + ns) < rend && (nptr - ns) >= nptr + w - (w % 1)) {
                t1 = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
                temp_pdif += t1 * t1;
            }
            if (i == 1 && (optr + os) && (nptr - ns) >= nptr + w - (w % 1)) {
                t2 = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
                temp_bdif += t2 * t2;
            }
        }
        pdif += temp_pdif;
        bdif += temp_bdif;
    }
}
