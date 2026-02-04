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
    // Variant 2: Reverse sequential access
    for (i = nb_samples - 1; i >= 0; i--) {
        int32_t M = samples_l[i];
        magdata |= (M < 0) ? ~M : M;
        xordata |= M ^ -(M & 1);
        anddata &= M;
        ordata |= M;
        if ((ordata & 1) && !(anddata & 1) && (xordata & 2))
            return;
    }
}
