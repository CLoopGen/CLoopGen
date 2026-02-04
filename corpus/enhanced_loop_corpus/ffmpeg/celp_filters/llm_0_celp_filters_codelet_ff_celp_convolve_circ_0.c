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
            int16_t temp = fc_in[i];
            for (k = 0; k < len; k++) {
                if (k < i) {
                    fc_out[k] += (temp * filter[len + k - i]) >> 15;
                } else {
                    fc_out[k] += (temp * filter[k - i]) >> 15;
                }
            }
        }
    }
}
