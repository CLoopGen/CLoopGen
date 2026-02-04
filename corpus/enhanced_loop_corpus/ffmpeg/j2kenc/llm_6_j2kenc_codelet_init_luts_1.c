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
    int temp_sig = ((3 * i << (13 - (7 - 1))) - (9 << 11));
    lut_nmsedec_sig[i] = (temp_sig > 0 ? temp_sig : 0);
    
    int temp_sq = i * i;
    int temp_sig0_val = ((temp_sq + (1 << (7 - 1) - 1)) & mask) << 1;
    lut_nmsedec_sig0[i] = (temp_sig0_val > 0 ? temp_sig0_val : 0);
    
    a = (i >> (7 - 2) & 2) + 1;
    
    int ref_term1 = (a - 2) * (i << (13 - (7 - 1)));
    int ref_term2 = (1 << 13) - (a * a << 11);
    int temp_ref = ref_term1 + ref_term2;
    lut_nmsedec_ref[i] = (temp_ref > 0 ? temp_ref : 0);
    
    int ref0_expr = (temp_sq - (i << 7) + (1 << 2 * (7 - 1)) + (1 << ((7 - 1) - 1))) & mask;
    int temp_ref0 = ref0_expr << 1;
    lut_nmsedec_ref0[i] = (temp_ref0 > 0 ? temp_ref0 : 0);
}
}
