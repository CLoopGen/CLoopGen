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
    for (int outer = 0; outer < w / 2; outer++) {
        uint16_t *n_cur = nptr + outer * 2;
        uint16_t *o_cur = optr + outer * 2;
        uint16_t *n_next = n_cur + 1;
        uint16_t *o_next = o_cur + 1;

        for (int inner = 0; inner < 2 && (n_cur + inner) < rend; inner++) {
            uint16_t *n_ptr = (inner == 0) ? n_cur : n_next;
            uint16_t *o_ptr = (inner == 0) ? o_cur : o_next;

            int64_t t_val = ((*n_ptr - n_ptr[ns]) << 2) + n_ptr[(ns) << 1] - n_ptr[-ns];
            pdif += t_val * t_val;

            t_val = ((*o_ptr - n_ptr[ns]) << 2) + o_ptr[(os) << 1] - n_ptr[-ns];
            tdif += t_val * t_val;
        }
    }

    // Handle odd width
    if (w % 2 != 0) {
        uint16_t *n_last = nptr + w - 1;
        uint16_t *o_last = optr + w - 1;
        int64_t t_val = ((*n_last - n_last[ns]) << 2) + n_last[(ns) << 1] - n_last[-ns];
        pdif += t_val * t_val;
        t_val = ((*o_last - n_last[ns]) << 2) + o_last[(os) << 1] - n_last[-ns];
        tdif += t_val * t_val;
    }
}
