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
    for (int outer = 0; outer < w / 2; outer++) {
        uint16_t *n_cur = nptr + outer;
        uint16_t *o_cur = optr + outer;
        uint16_t *n_ns = n_cur + ns;
        uint16_t *n_mns = n_cur - ns;
        uint16_t *o_ons = o_cur + (os << 1);

        int64_t t1 = (((*n_cur) - n_ns[0]) << 2) + n_ns[ns] - n_mns[0];
        pdif += t1 * t1;

        int64_t t2 = (((*o_cur) - n_ns[0]) << 2) + o_ons[0] - n_mns[0];
        bdif += t2 * t2;

        n_cur = nptr + (w - 1 - outer);
        o_cur = optr + (w - 1 - outer);
        n_ns = n_cur + ns;
        n_mns = n_cur - ns;
        o_ons = o_cur + (os << 1);

        t1 = (((*n_cur) - n_ns[0]) << 2) + n_ns[ns] - n_mns[0];
        pdif += t1 * t1;

        t2 = (((*o_cur) - n_ns[0]) << 2) + o_ons[0] - n_mns[0];
        bdif += t2 * t2;
    }
    if (w % 2 == 1) {
        uint16_t *n_cur = nptr + w / 2;
        uint16_t *o_cur = optr + w / 2;
        int64_t t1 = (((*n_cur) - n_cur[ns]) << 2) + n_cur[(ns) << 1] - n_cur[-ns];
        int64_t t2 = (((*o_cur) - n_cur[ns]) << 2) + o_cur[(os) << 1] - n_cur[-ns];
        pdif += t1 * t1;
        bdif += t2 * t2;
    }
}
