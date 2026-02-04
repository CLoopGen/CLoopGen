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
for (i = 0; i < (60 << 2); i++) {
    *rseed = (int16_t)(*rseed * 521 + 259);
    out[i] = gain * *rseed >> 15;
}

}
