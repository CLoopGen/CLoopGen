#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *samples_l;
extern int nb_samples;
extern uint32_t magdata;
extern uint32_t ordata;
extern uint32_t xordata;
extern uint32_t anddata;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nb_samples; i += 2) {
        int32_t M1 = samples_l[i];
        int32_t M2 = (i + 1 < nb_samples) ? samples_l[i + 1] : M1;
        magdata |= (M1 < 0) ? ~M1 : M1;
        magdata |= (M2 < 0) ? ~M2 : M2;
        xordata |= M1 ^ -(M1 & 1);
        xordata |= M2 ^ -(M2 & 1);
        anddata &= M1 & M2;
        ordata |= M1 | M2;
        if ((ordata & 1) && !(anddata & 1) && (xordata & 2))
            return;
    }
}
