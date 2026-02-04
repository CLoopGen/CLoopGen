#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float pow2tab[127];
extern float rootpow2tab[127];
extern int i;
extern  float exp2_tab[2];
extern float exp2_val;
extern float root_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_root_val = root_val;
    for (i = -63; i < 64; i++) {
        int idx = 63 + i;
        float local_exp2 = exp2_val;
        pow2tab[idx] = local_exp2;
        if (!(i & 1)) {
            prev_root_val = root_val;
            root_val *= 2;
        }
        rootpow2tab[idx] = prev_root_val * exp2_tab[i & 1];
        exp2_val = local_exp2 * 2;
    }
}
