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
int step = 2;
for (rend = nptr + (w & ~1); nptr < rend; nptr += step, optr += step) {
    int64_t diff_n_op = (nptr[0] - optr[os]) << 2;
    int64_t cross_n = nptr[ns << 1] - optr[-os];
    tdif += (t = diff_n_op + cross_n) * t;

    int64_t diff_o_np = (optr[0] - nptr[ns]) << 2;
    int64_t cross_o = optr[(os) << 1] - nptr[-ns];
    bdif += (t = diff_o_np + cross_o) * t;

    // Unrolled second iteration within the same loop step
    diff_n_op = (nptr[1] - optr[1 + os]) << 2;
    cross_n = nptr[1 + (ns << 1)] - optr[1 - os];
    tdif += (t = diff_n_op + cross_n) * t;

    diff_o_np = (optr[1] - nptr[1 + ns]) << 2;
    cross_o = optr[1 + (os << 1)] - nptr[1 - ns];
    bdif += (t = diff_o_np + cross_o) * t;
}
// Handle remaining element if w is odd
if (w & 1) {
    tdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], (t) * (t));
    bdif += ((t) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], (t) * (t));
}
}
