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
    if (w > 0) {
        rend = nptr + w;
        for (int outer = 0; outer < w; outer += 4) {
            for (int inner = 0; inner < 4 && (nptr + outer + inner) < rend; inner++) {
                uint16_t *n_cur = nptr + outer + inner;
                uint16_t *o_cur = optr + outer + inner;
                int t1 = ((*n_cur - n_cur[ns]) << 2) + n_cur[(ns) << 1] - n_cur[-ns];
                int t2 = ((*n_cur - o_cur[os]) << 2) + n_cur[(ns) << 1] - o_cur[-os];
                pdif += t1 * t1;
                bdif += t2 * t2;
            }
        }
    }
}
