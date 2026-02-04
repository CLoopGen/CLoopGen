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
int step = 4;
for (i = 0; i < subframe_size; i += step) {
    int limit = (i + step < subframe_size) ? i + step : subframe_size;
    for (int k = i; k < limit; k++) {
        int32_t product_cur = gain_code * fc_cur[k];
        int32_t product_new = gain_code * fc_new[k];
        int32_t offset_cur = product_cur + 8192;
        int32_t offset_new = product_new + 8192;
        int32_t shift_cur = offset_cur >> 14;
        int32_t shift_new = offset_new >> 14;
        out[k] = in[k] - shift_cur + shift_new;
    }
}
}
