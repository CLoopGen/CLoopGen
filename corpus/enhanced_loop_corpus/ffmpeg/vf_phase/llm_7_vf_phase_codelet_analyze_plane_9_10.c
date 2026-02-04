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
    uint16_t *nptr_temp = nptr;
    uint16_t *optr_temp = optr;
    int64_t pdif_accum = 0;
    int64_t bdif_accum = 0;
    uint16_t *rend_temp = nptr_temp + w;

    for (int i = 0; i < w; i++) {
        int t1 = ((nptr_temp[i] - nptr_temp[i + ns]) << 2) + nptr_temp[i + (ns << 1)] - nptr_temp[i - ns];
        pdif_accum += t1 * t1;

        int t2 = ((optr_temp[i] - nptr_temp[i + ns]) << 2) + optr_temp[i + (os << 1)] - nptr_temp[i - ns];
        bdif_accum += t2 * t2;
    }

    pdif += pdif_accum;
    bdif += bdif_accum;
    nptr += w;
    optr += w;
}
