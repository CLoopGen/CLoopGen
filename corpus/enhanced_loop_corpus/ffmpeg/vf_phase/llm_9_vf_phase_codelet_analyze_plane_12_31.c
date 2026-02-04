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
    int64_t diff_p, diff_b, diff_t;
    // Unrolled by 2 for higher computational intensity
    // First element
    diff_p = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
    pdif += diff_p * diff_p;
    diff_b = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
    bdif += diff_b * diff_b;
    diff_t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
    tdif += diff_t * diff_t;

    // Second element
    uint16_t *nptr1 = nptr + 1;
    uint16_t *optr1 = optr + 1;
    diff_p = ((*(nptr1) - (nptr1)[ns]) << 2) + (nptr1)[(ns) << 1] - (nptr1)[-(ns)];
    pdif += diff_p * diff_p;
    diff_b = ((*(nptr1) - (optr1)[os]) << 2) + (nptr1)[(ns) << 1] - (optr1)[-(os)];
    bdif += diff_b * diff_b;
    diff_t = ((*(optr1) - (nptr1)[ns]) << 2) + (optr1)[(os) << 1] - (nptr1)[-(ns)];
    tdif += diff_t * diff_t;
}
// Handle leftover element if w is odd
if ((w & 1) && nptr < rend + 1) {
    t = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-(ns)];
    pdif += t * t;
    t = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-(os)];
    bdif += t * t;
    t = ((*(optr) - (nptr)[ns]) << 2) + (optr)[(os) << 1] - (nptr)[-(ns)];
    tdif += t * t;
}
}
