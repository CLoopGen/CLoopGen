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
    uint8_t *rend_local = nptr + w;
    int pdif_temp = 0;
    int tdif_temp = 0;
    int t1, t2;

    for (int i = 0; i < w; i++) {
        t1 = ((nptr[i] - nptr[i + ns]) << 2) + nptr[i + (ns << 1)] - nptr[i - ns];
        pdif_temp += t1 * t1;

        t2 = ((nptr[i] - optr[i + os]) << 2) + nptr[i + (ns << 1)] - optr[i - os];
        tdif_temp += t2 * t2;
    }

    pdif += pdif_temp;
    tdif += tdif_temp;
}
