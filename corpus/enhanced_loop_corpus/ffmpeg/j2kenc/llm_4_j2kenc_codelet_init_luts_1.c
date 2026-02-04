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
for (i = 0; i < (1 << 7); i++) {
    int val_sig = (3 * i << (13 - (7 - 1))) - (9 << 11);
    lut_nmsedec_sig[i] = val_sig > 0 ? val_sig : 0;

    int temp_sq = i * i + (1 << (7 - 1) - 1);
    lut_nmsedec_sig0[i] = ((temp_sq & mask) << 1) > 0 ? (temp_sq & mask) << 1 : 0;

    a = (i >> (7 - 2) & 2) + 1;
    int ref_val = (a - 2) * (i << (13 - (7 - 1))) + (1 << 13) - (a * a << 11);
    lut_nmsedec_ref[i] = ref_val > 0 ? ref_val : 0;

    int poly = i * i - (i << 7) + (1 << 2 * (7 - 1)) + (1 << ((7 - 1) - 1));
    lut_nmsedec_ref0[i] = ((poly & mask) << 1) > 0 ? (poly & mask) << 1 : 0;
}
}
