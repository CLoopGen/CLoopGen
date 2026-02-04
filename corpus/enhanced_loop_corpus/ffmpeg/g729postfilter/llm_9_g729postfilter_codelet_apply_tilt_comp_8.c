#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern int16_t *res_pst;
extern int subframe_size;
extern int tmp2;
extern int i;
extern int gt;
extern int ga;
extern int fact;
extern int sh_fact;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = subframe_size - 1; i >= 1; i--) {
    int16_t prediction = res_pst[i - 1];
    tmp2 = (gt * prediction) << 1;
    tmp2 = (tmp2 + 16384) >> 15;
    tmp2 = res_pst[i] + tmp2;
    tmp2 = (tmp2 * ga) >> sh_fact;
    if (tmp2 > 32767) tmp2 = 32767;
    else if (tmp2 < -32768) tmp2 = -32768;
    out[i] = (int16_t)tmp2;
}
}
