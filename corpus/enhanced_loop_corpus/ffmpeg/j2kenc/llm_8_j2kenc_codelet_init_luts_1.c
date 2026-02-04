#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int lut_nmsedec_ref[128];
extern int lut_nmsedec_ref0[128];
extern int lut_nmsedec_sig[128];
extern int lut_nmsedec_sig0[128];
extern int i;
extern int a;
extern int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (1 << 7); i += 2) {
    int temp1 = 3 * i << (13 - (7 - 1));
    int temp2 = 9 << 11;
    lut_nmsedec_sig[i] = (temp1 - temp2 > 0) ? temp1 - temp2 : 0;
    if (i + 1 < (1 << 7)) {
        lut_nmsedec_sig[i + 1] = ((3 * (i + 1) << (13 - (7 - 1))) - (9 << 11) > 0) ? 
                                 (3 * (i + 1) << (13 - (7 - 1))) - (9 << 11) : 0;
    }
    int sq = i * i;
    lut_nmsedec_sig0[i] = (((sq + (1 << (7 - 1) - 1)) & mask) << 1) > 0 ? 
                          ((sq + (1 << (7 - 1) - 1)) & mask) << 1 : 0;
    a = (i >> (7 - 2) & 2) + 1;
    int shift_val = i << (13 - (7 - 1));
    lut_nmsedec_ref[i] = (((a - 2) * shift_val + (1 << 13) - (a * a << 11)) > 0) ? 
                         (a - 2) * shift_val + (1 << 13) - (a * a << 11) : 0;
    int poly = sq - (i << 7) + (1 << 2 * (7 - 1)) + (1 << ((7 - 1) - 1));
    lut_nmsedec_ref0[i] = ((poly & mask) << 1) > 0 ? (poly & mask) << 1 : 0;
}
}
