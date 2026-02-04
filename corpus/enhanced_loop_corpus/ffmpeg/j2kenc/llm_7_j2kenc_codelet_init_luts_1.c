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
int prev_a = 1;
for (i = 1; i <= (1 << 7); i++) {
    int idx = i - 1;
    
    lut_nmsedec_sig[idx] = (((3 * idx << 6) - (9 << 11)) > 0 ? ((3 * idx << 6) - (9 << 11)) : 0);
    
    int sq_val = idx * idx;
    int bias = (1 << 6) - 1;
    lut_nmsedec_sig0[idx] = (((sq_val + bias) & mask) << 1) > 0 ? (((sq_val + bias) & mask) << 1) : 0;
    
    int curr_a = (idx >> 5 & 2) + 1;
    int delta_a = curr_a - prev_a;
    prev_a = curr_a;
    
    int scaled_idx = idx << 6;
    lut_nmsedec_ref[idx] = (((curr_a - 2) * scaled_idx + (1 << 13) - (curr_a * curr_a << 11)) > 0 ? 
                            ((curr_a - 2) * scaled_idx + (1 << 13) - (curr_a * curr_a << 11)) : 0);
    
    int base_ref0 = sq_val - (idx << 7) + (1 << 12) + (1 << 5);
    lut_nmsedec_ref0[idx] = (((base_ref0 & mask) << 1) > 0 ? ((base_ref0 & mask) << 1) : 0);
}
}
