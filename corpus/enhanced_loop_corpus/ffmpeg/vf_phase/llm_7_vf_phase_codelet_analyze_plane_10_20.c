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
    for (rend = nptr + w; nptr < rend; nptr += 2, optr += 2) {
        if (nptr + 1 >= rend) break;
        int t_n0 = (*(nptr) - optr[os]) << 2;
        int t_n1 = (*(nptr + 1) - (optr + 1)[os]) << 2;
        int t_o0 = (*(optr) - nptr[ns]) << 2;
        int t_o1 = (*(optr + 1) - (nptr + 1)[ns]) << 2;

        int val_n0 = t_n0 + nptr[(ns) << 1] - optr[-(os)];
        int val_n1 = t_n1 + (nptr + 1)[(ns) << 1] - (optr + 1)[-(os)];
        int val_o0 = t_o0 + optr[(os) << 1] - nptr[-(ns)];
        int val_o1 = t_o1 + (optr + 1)[(os) << 1] - (nptr + 1)[-(ns)];

        tdif += (val_n0 * val_n0) + (val_n1 * val_n1);
        bdif += (val_o0 * val_o0) + (val_o1 * val_o1);
    }
    // Handle odd-sized w if needed
    if ((w % 2) == 1) {
        int t1 = ((*(nptr) - optr[os]) << 2) + nptr[(ns) << 1] - optr[-(os)];
        int t2 = ((*(optr) - nptr[ns]) << 2) + optr[(os) << 1] - nptr[-(ns)];
        tdif += t1 * t1;
        bdif += t2 * t2;
    }
}
