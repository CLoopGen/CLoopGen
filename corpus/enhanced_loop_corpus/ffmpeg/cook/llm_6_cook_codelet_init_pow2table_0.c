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
    float temp_exp2 = exp2_val;
    float temp_root = root_val;
    for (i = -63; i < 64; i++) {
        pow2tab[63 + i] = temp_exp2;
        if (!(i & 1) && i > -63)
            temp_root *= 2;
        rootpow2tab[63 + i] = temp_root * exp2_tab[i & 1];
        temp_exp2 *= 2;
    }
    exp2_val = temp_exp2;
    root_val = temp_root;
}
