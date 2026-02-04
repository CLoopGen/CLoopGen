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
            for (int j = 0; j < 1; j++) {
                for (k = 0; k < i; k++)
                    fc_out[k] += (fc_in[i] * filter[len + k - i]) >> 15;
                for (k = i; k < len; k++)
                    fc_out[k] += (fc_in[i] * filter[k - i]) >> 15;
            }
        }
    }
}
