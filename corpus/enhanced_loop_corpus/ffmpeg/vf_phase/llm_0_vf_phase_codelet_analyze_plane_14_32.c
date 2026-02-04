#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint16_t *nptr;
extern  uint16_t *optr;
extern  int w;
extern int64_t tdif;
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int64_t temp_n = (*(nptr) - nptr[ns]) << 2;
        int64_t temp_o = (*(nptr) - optr[os]) << 2;
        pdif += ((t) = temp_n + nptr[(ns) << 1] - nptr[-ns], (int64_t)(t) * t);
        tdif += ((t) = temp_o + nptr[(ns) << 1] - optr[-os], (int64_t)(t) * t);
    }
}
