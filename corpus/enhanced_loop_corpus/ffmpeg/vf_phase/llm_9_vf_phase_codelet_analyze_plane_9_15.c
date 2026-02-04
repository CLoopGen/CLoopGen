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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (rend = nptr + (w >> 2); nptr < rend; nptr++, optr++) {
    int64_t p_temp = 0, b_temp = 0, t_temp = 0;
    for (int i = 0; i < 4; ++i) {
        uint16_t *cur_n = nptr + i;
        uint16_t *cur_o = optr + i;
        p_temp += ((t) = ((*(cur_n) - cur_n[ns]) << 2) + cur_n[(ns) << 1] - cur_n[-ns], (t) * (t));
        b_temp += ((t) = ((*(cur_n) - cur_o[os]) << 2) + cur_n[(ns) << 1] - cur_o[-os], (t) * (t));
        t_temp += ((t) = ((*(cur_o) - cur_n[ns]) << 2) + cur_o[(os) << 1] - cur_n[-ns], (t) * (t));
    }
    pdif += p_temp;
    bdif += b_temp;
    tdif += t_temp;
}
}
