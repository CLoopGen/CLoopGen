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
for (i = 0; i < len; i += 2) {
    if (fc_in[i]) {
        int16_t val = fc_in[i];
        for (k = 0; k < i; k++)
            fc_out[k] += (val * filter[len + k - i]) >> 15;
        for (k = i; k < len; k++)
            fc_out[k] += (val * filter[k - i]) >> 15;
    }
    if (i + 1 < len && fc_in[i + 1]) {
        int16_t val = fc_in[i + 1];
        for (k = 0; k < i + 1; k++)
            fc_out[k] += (val * filter[len + k - (i + 1)]) >> 15;
        for (k = i + 1; k < len; k++)
            fc_out[k] += (val * filter[k - (i + 1)]) >> 15;
    }
}
}
