#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *fc_out;
extern  int16_t *fc_in;
extern  int16_t *filter;
extern int len;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t temp_accum = 0;
    for (i = 0; i < len; i++) {
        if (fc_in[i]) {
            temp_accum = fc_in[i];
            for (k = 0; k < i; k++) {
                int16_t filtered_val = filter[len + k - i];
                fc_out[k] = (int16_t)((fc_out[k] + ((temp_accum * filtered_val) >> 15)) & 0xFFFF);
            }
            for (k = i; k < len; k++) {
                int16_t filtered_val = filter[k - i];
                fc_out[k] = (int16_t)((fc_out[k] + ((temp_accum * filtered_val) >> 15)) & 0xFFFF);
            }
        }
    }
}
