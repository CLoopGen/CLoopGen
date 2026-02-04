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
for (i = 0; i < nb_samples; i++) {
    int32_t M = samples_l[i];
    magdata |= (M < 0) ? ~M : M;
    xordata |= M ^ -(M & 1);
    anddata &= M;
    ordata |= M;

    if (!(ordata & 1) || (anddata & 1)) continue;
    if (xordata & 2)
        return;
}
}
