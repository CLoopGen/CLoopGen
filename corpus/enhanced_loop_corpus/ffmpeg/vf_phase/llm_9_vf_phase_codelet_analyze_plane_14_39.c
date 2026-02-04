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
extern int64_t pdif;
extern int t;
extern  uint16_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
for (rend = nptr + (w & ~1); nptr < rend; nptr += stride, optr += stride) {
    int64_t t_val;
    // Unroll and combine two iterations into one with reduced operations
    pdif += ((t_val) = ((*(nptr) - (nptr)[ns]) << 1) + (nptr)[(ns) << 1] - (nptr)[-(ns)], t_val * t_val);
    bdif += ((t_val) = ((*(nptr) - (optr)[os]) << 1) + (nptr)[(ns) << 1] - (optr)[-(os)], t_val * t_val);
    tdif += ((t_val) = ((*(optr) - (nptr)[ns]) << 1) + (optr)[(os) << 1] - (nptr)[-(ns)], t_val * t_val);

    // Second part of unrolled iteration
    pdif += ((t_val) = ((*(nptr+1) - (nptr+1)[ns]) << 1) + (nptr+1)[(ns) << 1] - (nptr+1)[-(ns)], t_val * t_val);
    bdif += ((t_val) = ((*(nptr+1) - (optr+1)[os]) << 1) + (nptr+1)[(ns) << 1] - (optr+1)[-(os)], t_val * t_val);
    tdif += ((t_val) = ((*(optr+1) - (nptr+1)[ns]) << 1) + (optr+1)[(os) << 1] - (nptr+1)[-(ns)], t_val * t_val);
}
// Handle remaining element if w was odd
if ((w & 1) && nptr < rend + (w & 1)) {
    int64_t t_val;
    pdif += ((t_val) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)], t_val * t_val);
    bdif += ((t_val) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)], t_val * t_val);
    tdif += ((t_val) = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)], t_val * t_val);
}
}
