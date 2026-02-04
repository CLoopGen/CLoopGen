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
    int64_t t_n1, t_b1, t_n2, t_b2;
    
    // First element
    t_n1 = ((*(nptr) - (nptr)[ns]) << 2) + (nptr)[ns << 1] - (nptr)[-ns];
    t_b1 = ((*(nptr) - (optr)[os]) << 2) + (nptr)[ns << 1] - (optr)[-os];
    pdif += t_n1 * t_n1;
    bdif += t_b1 * t_b1;

    // Second element (if within bounds)
    if (nptr + 1 < rend) {
        t_n2 = ((*(nptr+1) - (nptr+1)[ns]) << 2) + (nptr+1)[ns << 1] - (nptr+1)[-ns];
        t_b2 = ((*(nptr+1) - (optr+1)[os]) << 2) + (nptr+1)[ns << 1] - (optr+1)[-os];
        pdif += t_n2 * t_n2;
        bdif += t_b2 * t_b2;
    }
}
}
