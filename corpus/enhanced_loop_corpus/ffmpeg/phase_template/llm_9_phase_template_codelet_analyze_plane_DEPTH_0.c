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
    for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
        int64_t temp_pdif = 0, temp_tdif = 0;
        for (int i = 0; i < 4; ++i) {
            uint16_t *curr_n = nptr + i;
            uint16_t *curr_o = optr + i;
            int64_t t1 = ((*(curr_n) - curr_n[ns]) << 2) + curr_n[(ns) << 1] - curr_n[-ns];
            int64_t t2 = ((*(curr_n) - curr_o[os]) << 2) + curr_n[(ns) << 1] - curr_o[-os];
            temp_pdif += t1 * t1;
            temp_tdif += t2 * t2;
        }
        pdif += temp_pdif;
        tdif += temp_tdif;
        nptr += 3; optr += 3;
    }
}
