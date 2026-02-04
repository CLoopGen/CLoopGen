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
for (rend = nptr + (w >> 1); nptr < rend; nptr++, optr++) {
    int64_t temp_bdif = 0, temp_tdif = 0;
    for (int i = 0; i < 2 && nptr + i < rend; ++i) {
        int64_t n_val = (nptr)[i], o_val = (optr)[i];
        int64_t b_term = ((n_val - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
        int64_t t_term = ((o_val - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
        temp_bdif += b_term * b_term;
        temp_tdif += t_term * t_term;
    }
    bdif += temp_bdif;
    tdif += temp_tdif;
}
}
