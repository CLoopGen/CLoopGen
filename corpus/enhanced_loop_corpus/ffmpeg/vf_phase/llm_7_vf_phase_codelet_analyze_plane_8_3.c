#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pdif = 0;
    bdif = 0;
    uint8_t *temp_nptr = nptr;
    uint8_t *temp_optr = optr;
    for (rend = temp_nptr + w; temp_nptr < rend; temp_nptr++, temp_optr++) {
        int diff_n = (temp_nptr[ns] - *(temp_nptr)) << 2;
        int corr_n = temp_nptr[-ns] - temp_nptr[(ns) << 1];
        int t_n = diff_n - corr_n;
        pdif += t_n * t_n;

        int diff_o = (temp_optr[os] - *(temp_nptr)) << 2;
        int corr_o = temp_optr[-os] - temp_nptr[(ns) << 1];
        int t_b = diff_o - corr_o;
        bdif += t_b * t_b;
    }
    nptr = temp_nptr;
    optr = temp_optr;
}
