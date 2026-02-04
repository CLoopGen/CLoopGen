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
    pdif = 0;
    bdif = 0;
    uint16_t *temp_nptr = nptr;
    uint16_t *temp_optr = optr;
    for (int i = 0; i < w; i++) {
        int diff_n = (temp_nptr[i] - temp_nptr[i + ns]) << 2;
        diff_n += temp_nptr[i + (ns << 1)] - temp_nptr[i - ns];
        int diff_b = (temp_nptr[i] - temp_optr[i + os]) << 2;
        diff_b += temp_nptr[i + (ns << 1)] - temp_optr[i - os];
        pdif += diff_n * diff_n;
        bdif += diff_b * diff_b;
    }
    nptr += w;
    optr += w;
}
