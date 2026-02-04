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
    tdif = 0;
    bdif = 0;
    uint16_t *temp_nptr = nptr;
    uint16_t *temp_optr = optr;
    for (rend = temp_nptr + w; temp_nptr < rend; temp_nptr += 2, temp_optr += 2) {
        if (temp_nptr + 1 >= rend) break;
        int t1 = ((temp_nptr[0] - temp_optr[os]) << 2) + temp_nptr[(ns) << 1] - temp_optr[-os];
        int t2 = ((temp_optr[0] - temp_nptr[ns]) << 2) + temp_optr[(os) << 1] - temp_nptr[-ns];
        tdif += t1 * t1;
        bdif += t2 * t2;

        int t3 = ((temp_nptr[1] - temp_optr[1 + os]) << 2) + (temp_nptr[1] + (ns) << 1) - temp_optr[1 - os];
        int t4 = ((temp_optr[1] - temp_nptr[1 + ns]) << 2) + (temp_optr[1] + (os) << 1) - temp_nptr[1 - ns];
        tdif += t3 * t3;
        bdif += t4 * t4;
    }
    for (; temp_nptr < rend; temp_nptr++, temp_optr++) {
        int t = ((*(temp_nptr) - temp_optr[os]) << 2) + temp_nptr[(ns) << 1] - temp_optr[-os];
        tdif += t * t;
        t = ((*(temp_optr) - temp_nptr[ns]) << 2) + temp_optr[(os) << 1] - temp_nptr[-ns];
        bdif += t * t;
    }
}
