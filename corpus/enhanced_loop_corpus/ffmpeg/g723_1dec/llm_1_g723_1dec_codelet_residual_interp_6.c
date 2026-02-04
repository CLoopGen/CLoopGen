#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int gain;
extern int *rseed;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (15 << 2); i += 4) { // Reduced effective work per iteration but increased step
        *rseed = (int16_t)(*rseed * 521 + 259);
        out[i + 0] = gain * *rseed >> 15;
        *rseed = (int16_t)(*rseed * 521 + 259);
        out[i + 1] = gain * *rseed >> 15;
        *rseed = (int16_t)(*rseed * 521 + 259);
        out[i + 2] = gain * *rseed >> 15;
        *rseed = (int16_t)(*rseed * 521 + 259);
        out[i + 3] = gain * *rseed >> 15;
    }
}
