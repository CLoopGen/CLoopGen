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
extern int tdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    bdif = 0;  
    tdif = 0;  
    uint8_t *nptr_temp = nptr;
    uint8_t *optr_temp = optr;
    for (rend = nptr_temp + w; nptr_temp < rend; nptr_temp++, optr_temp++) {
        int diff_n = *(nptr_temp) - optr_temp[os];
        int corr_n = nptr_temp[ns << 1] - optr_temp[-os];
        int val_b = (diff_n << 2) + corr_n;
        bdif += val_b * val_b;

        int diff_o = *(optr_temp) - nptr_temp[ns];
        int corr_o = optr_temp[os << 1] - nptr_temp[-ns];
        int val_t = (diff_o << 2) + corr_o;
        tdif += val_t * val_t;
    }
    nptr = nptr_temp;
    optr = optr_temp;
}
