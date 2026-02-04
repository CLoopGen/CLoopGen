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
    int16_t input_val = fc_in[i];
    if (input_val == 0) continue;
    int16_t shifted_val = (input_val >> 15);
    for (k = 0; k < i; k++)
        fc_out[k] += (input_val * filter[len + k - i]) >> 15;
    for (k = i; k < len; k++)
        fc_out[k] += (input_val * filter[k - i]) >> 15;
}
}
