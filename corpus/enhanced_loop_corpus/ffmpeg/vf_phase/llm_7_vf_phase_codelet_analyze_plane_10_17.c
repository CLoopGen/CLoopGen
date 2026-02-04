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
    pdif = 0;
    tdif = 0;
    uint16_t *temp_nptr = nptr;
    uint16_t *temp_optr = optr;
    for (int i = 0; i < w; i++) {
        int t_val_n = ((temp_nptr[i] - temp_nptr[i + ns]) << 2) + temp_nptr[i + (ns << 1)] - temp_nptr[i - ns];
        int t_val_o = ((temp_optr[i] - temp_nptr[i + ns]) << 2) + temp_optr[i + (os << 1)] - temp_nptr[i - ns];
        pdif += t_val_n * t_val_n;
        tdif += t_val_o * t_val_o;
    }
}
