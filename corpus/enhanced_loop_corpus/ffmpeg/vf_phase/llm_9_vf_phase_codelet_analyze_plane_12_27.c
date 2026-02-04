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
const int stride_n = ns * 2;
const int stride_o = os * 2;
for (rend = nptr + (w & ~1); nptr < rend; nptr += 2, optr += 2) {
    int64_t t_n1 = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[stride_n] - (nptr)[-ns];
    int64_t t_n2 = (((nptr)[1] - (nptr)[ns+1]) << 2) + (nptr)[stride_n+1] - (nptr)[-ns+1];
    int64_t t_o1 = ((*(nptr) - (optr)[os]) << 2) + (nptr)[stride_n] - (optr)[-os];
    int64_t t_o2 = (((nptr)[1] - (optr)[os+1]) << 2) + (nptr)[stride_n+1] - (optr)[-os+1];
    pdif += t_n1 * t_n1 + t_n2 * t_n2;
    bdif += t_o1 * t_o1 + t_o2 * t_o2;
}
// Handle leftover element if w is odd
if (w & 1) {
    pdif += ((t) = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[(ns) << 1] - (nptr)[-ns], (t) * (t));
    bdif += ((t) = ((*(nptr) - (optr)[os]) << 2) + (nptr)[(ns) << 1] - (optr)[-os], (t) * (t));
}
}
