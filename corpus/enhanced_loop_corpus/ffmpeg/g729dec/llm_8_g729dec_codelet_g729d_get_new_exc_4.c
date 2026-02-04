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
int j;
for (i = 0; i < subframe_size; i += 2) {
    for (j = 0; j < 2 && (i + j) < subframe_size; j++) {
        int idx = i + j;
        int16_t temp = in[idx];
        int32_t cur_val = (gain_code * fc_cur[idx] + 8192) >> 14;
        int32_t new_val = (gain_code * fc_new[idx] + 8192) >> 14;
        out[idx] = temp - cur_val + new_val;
    }
}
}
