#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *fc_cur;
extern int gain_code;
extern int subframe_size;
extern int i;
extern int16_t fc_new[40];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i1;
    for (i1 = 0; i1 < subframe_size; i1++) {
        out[i1] = in[i1];
        out[i1] -= (gain_code * fc_cur[i1] + 8192) >> 14;
        out[i1] += (gain_code * fc_new[i1] + 8192) >> 14;
    }
}
