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
    for (int i = 0; i < w; i += 2) {
        uint16_t *n_cur1 = nptr + i;
        uint16_t *o_cur1 = optr + i;
        uint16_t *n_cur2 = nptr + i + 1;
        uint16_t *o_cur2 = optr + i + 1;

        if (i + 1 < w) {
            int64_t t1_n = ((*(n_cur1) - n_cur1[ns]) << 2) + n_cur1[(ns) << 1] - n_cur1[-ns];
            int64_t t1_o = ((*(o_cur1) - n_cur1[ns]) << 2) + o_cur1[(os) << 1] - n_cur1[-ns];
            pdif += t1_n * t1_n;
            tdif += t1_o * t1_o;

            int64_t t2_n = ((*(n_cur2) - n_cur2[ns]) << 2) + n_cur2[(ns) << 1] - n_cur2[-ns];
            int64_t t2_o = ((*(o_cur2) - n_cur2[ns]) << 2) + o_cur2[(os) << 1] - n_cur2[-ns];
            pdif += t2_n * t2_n;
            tdif += t2_o * t2_o;
        } else {
            int64_t t_n = ((*(n_cur1) - n_cur1[ns]) << 2) + n_cur1[(ns) << 1] - n_cur1[-ns];
            int64_t t_o = ((*(o_cur1) - n_cur1[ns]) << 2) + o_cur1[(os) << 1] - n_cur1[-ns];
            pdif += t_n * t_n;
            tdif += t_o * t_o;
        }
    }
}
