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
    // Variant 2: Strided memory access with increased stride factor
    // Access elements with a fixed stride of 2 to reduce total iterations and change access pattern
    int stride = 2;
    int limit = w / stride;
    uint16_t *n_cur = nptr;
    uint16_t *o_cur = optr;

    for (int i = 0; i < limit; i++) {
        // Compute current and offset positions using stride
        uint16_t n_val = n_cur[0];
        uint16_t o_val = o_cur[0];
        uint16_t n_ns2 = n_cur[(ns << 1) * stride];
        uint16_t o_os2 = o_cur[(os << 1) * stride];
        uint16_t n_neg_ns = n_cur[-(ns * stride)];
        uint16_t o_neg_os = o_cur[-(os * stride)];

        int t1 = ((n_val - o_val) << 2) + n_ns2 - o_neg_os;
        tdif += t1 * t1;

        int t2 = ((o_val - n_val) << 2) + o_os2 - n_neg_ns;
        bdif += t2 * t2;

        n_cur += stride;
        o_cur += stride;
    }
}
