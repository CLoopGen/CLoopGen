#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ns;
extern  int os;
extern  uint8_t *nptr;
extern  uint8_t *optr;
extern  int w;
extern int bdif;
extern int pdif;
extern int t;
extern  uint8_t *rend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pdif = 0;
    bdif = 0;
    for (rend = nptr + w; nptr < rend; nptr++, optr++) {
        int diff_n = (nptr)[ns];
        int val_n = *(nptr);
        int neg_n = (nptr)[-(ns)];
        int shift_n = (nptr)[(ns) << 1];
        int t_n = ((val_n - diff_n) << 2) + shift_n - neg_n;
        pdif += t_n * t_n;

        int diff_op = (nptr)[ns];
        int val_op = *(optr);
        int shift_op = (optr)[(os) << 1];
        int t_b = ((val_op - diff_op) << 2) + shift_op - neg_n;
        bdif += t_b * t_b;
    }
}
