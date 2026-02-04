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
        uint16_t *n_cur = nptr + outer;
        uint16_t *o_cur = optr + outer;
        for (int inner = 0; inner < 2 && n_cur < rend; inner++, n_cur++, o_cur++) {
            pdif += ((t) = ((*(n_cur) - (n_cur)[ns]) << 2) + (n_cur)[(ns) << 1] - (n_cur)[-(ns)], (t) * (t));
            tdif += ((t) = ((*(n_cur) - (o_cur)[os]) << 2) + (n_cur)[(ns) << 1] - (o_cur)[-(os)], (t) * (t));
        }
    }
    if (w % 2 != 0) {
        uint16_t *n_cur = nptr + w - 1;
        uint16_t *o_cur = optr + w - 1;
        pdif += ((t) = ((*(n_cur) - (n_cur)[ns]) << 2) + (n_cur)[(ns) << 1] - (n_cur)[-(ns)], (t) * (t));
        tdif += ((t) = ((*(n_cur) - (o_cur)[os]) << 2) + (n_cur)[(ns) << 1] - (o_cur)[-(os)], (t) * (t));
    }
}
