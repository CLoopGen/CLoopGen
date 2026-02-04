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
        if (res_pst[i - 1] == 0) {
            out[i] = 0;
            continue;
        }
        tmp2 = (gt * res_pst[i - 1]) * 2 + 16384;
        tmp2 = res_pst[i] + (tmp2 >> 15);
        tmp2 = (tmp2 * ga + fact) >> sh_fact;
        out[i] = tmp2;
    }
}
