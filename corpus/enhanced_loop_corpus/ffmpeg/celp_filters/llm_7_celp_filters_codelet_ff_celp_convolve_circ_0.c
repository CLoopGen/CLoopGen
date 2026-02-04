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
    int16_t* out = fc_out;
    int16_t* in = fc_in;
    for (i = 0; i < len; i++) {
        if (in[i]) {
            int16_t in_val = in[i];
            for (k = 0; k < i; k++) {
                int32_t product = in_val * filter[len + k - i];
                out[k] += (int16_t)(product >> 15);
            }
            for (k = i; k < len; k++) {
                int32_t product = in_val * filter[k - i];
                out[k] += (int16_t)(product >> 15);
            }
        }
    }
}
