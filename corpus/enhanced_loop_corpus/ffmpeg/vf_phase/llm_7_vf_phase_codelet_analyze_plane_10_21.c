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
    uint16_t *nptr_base = nptr;
    uint16_t *optr_base = optr;
    int64_t bdif_temp = bdif;
    int64_t tdif_temp = tdif;
    int64_t t1, t2;

    for (int i = 0; i < w; i++) {
        // Introduce WAW independence by separating updates to bdif and tdif
        t1 = ((nptr_base[i] - optr_base[i + os]) << 2) + nptr_base[i + (ns << 1)] - optr_base[i - os];
        t2 = ((optr_base[i] - nptr_base[i + ns]) << 2) + optr_base[i + (os << 1)] - nptr_base[i - ns];

        bdif_temp += t1 * t1;
        tdif_temp += t2 * t2;
    }

    bdif = bdif_temp;
    tdif = tdif_temp;
}
