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
    for (i = -63; i < 64; i++) {
        if (!(i & 1)) {
            root_val *= 2;
        }
        pow2tab[63 + i] = exp2_val;
        rootpow2tab[63 + i] = root_val * exp2_tab[i & 1];
        exp2_val *= 2;
    }
}
