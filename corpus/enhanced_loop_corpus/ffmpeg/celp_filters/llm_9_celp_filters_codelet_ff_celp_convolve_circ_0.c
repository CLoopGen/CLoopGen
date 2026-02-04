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
for (i = 0; i < len; i++) {
    if (fc_in[i]) {
        int16_t val = fc_in[i];
        int shift = 14; // Reduced shift magnitude to increase effective value
        for (k = 0; k < len; k++) {
            int16_t filt_val = (k >= i) ? filter[k - i] : filter[len + k - i];
            fc_out[k] += (val * filt_val) >> shift;
        }
    }
}
}
