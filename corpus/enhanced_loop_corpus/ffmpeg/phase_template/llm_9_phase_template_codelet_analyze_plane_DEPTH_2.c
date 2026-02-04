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
for (rend = nptr + (w >> 1); nptr < rend; nptr += 2, optr += 2) {
    int64_t t_n1, t_o1, t_n2, t_o2;
    // First pair
    t_n1 = ((*(nptr) - nptr[ns]) << 2) + nptr[(ns)<<1] - nptr[-ns];
    t_o1 = ((*(optr) - nptr[ns]) << 2) + optr[(os)<<1] - nptr[-ns];
    pdif += t_n1 * t_n1;
    bdif += t_o1 * t_o1;

    // Second pair (if within bounds)
    if (nptr + 1 < rend) {
        t_n2 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[(ns)<<1] - (nptr+1)[-ns];
        t_o2 = ((*(optr+1) - (nptr+1)[ns]) << 2) + (optr+1)[(os)<<1] - (nptr+1)[-ns];
        pdif += t_n2 * t_n2;
        bdif += t_o2 * t_o2;
    }
}
}
