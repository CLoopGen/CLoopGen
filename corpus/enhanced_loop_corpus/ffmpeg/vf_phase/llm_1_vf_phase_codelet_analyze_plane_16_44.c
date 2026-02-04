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
    for (int i = 0; i < w; i++) {
        uint16_t *n_cur = nptr + i;
        uint16_t *o_cur = optr + i;
        int64_t t1 = (( *n_cur - o_cur[os]) << 2) + n_cur[ns << 1] - o_cur[-os];
        int64_t t2 = (( *o_cur - n_cur[ns]) << 2) + o_cur[os << 1] - n_cur[-ns];
        tdif += t1 * t1;
        bdif += t2 * t2;
    }
}
