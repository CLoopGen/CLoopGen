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
    if (w <= 0) return;
    for (int outer = 0; outer < w; outer += 8) {
        for (int inner = 0; inner < 8 && (outer + inner) < w; inner++) {
            uint16_t* curr_n = nptr + outer + inner;
            uint16_t* curr_o = optr + outer + inner;
            int t1 = ((*curr_n - curr_n[ns]) << 2) + curr_n[(ns) << 1] - curr_n[-ns];
            int t2 = ((*curr_o - curr_n[ns]) << 2) + curr_o[(os) << 1] - curr_n[-ns];
            pdif += t1 * t1;
            bdif += t2 * t2;
        }
    }
}
