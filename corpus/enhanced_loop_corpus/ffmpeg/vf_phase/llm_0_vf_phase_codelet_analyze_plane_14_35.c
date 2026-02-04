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
            t1 = ((*(nptr + i) - (nptr + i)[ns]) << 2) + (nptr + i)[(ns) << 1] - (nptr + i)[-(ns)];
            temp_pdif += t1 * t1;
            t2 = ((*(nptr + i) - (optr + i)[os]) << 2) + (nptr + i)[(ns) << 1] - (optr + i)[-(os)];
            temp_bdif += t2 * t2;
        }
        pdif += temp_pdif;
        bdif += temp_bdif;
    }
}
