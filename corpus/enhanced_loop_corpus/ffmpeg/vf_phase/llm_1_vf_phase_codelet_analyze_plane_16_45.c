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
    if (w <= 0) return;
    for (int outer = 0; outer < w; outer += 4) {
        int chunk = (w - outer) < 4 ? (w - outer) : 4;
        for (int inner = 0; inner < chunk; inner++) {
            int offset = outer + inner;
            uint16_t* curr_n = nptr + offset;
            uint16_t* curr_o = optr + offset;

            int t1 = ((curr_n[0] - curr_o[os]) << 2) + curr_n[(ns) << 1] - curr_o[-(os)];
            bdif += t1 * t1;

            int t2 = ((curr_o[0] - curr_n[ns]) << 2) + curr_o[(os) << 1] - curr_n[-(ns)];
            tdif += t2 * t2;
        }
    }
}
