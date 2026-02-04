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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp_pdif = 0, temp_bdif = 0, temp_tdif = 0;
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        t = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
        temp_pdif += t * t;

        t = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
        temp_bdif += t * t;

        t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        temp_tdif += t * t;
    }
    pdif += temp_pdif;
    bdif += temp_bdif;
    tdif += temp_tdif;
}
