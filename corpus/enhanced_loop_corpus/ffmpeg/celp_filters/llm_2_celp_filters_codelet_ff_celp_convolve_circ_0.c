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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing fc_in[i] directly in the outer loop, we use a pointer with stride 2
    // to simulate strided access. The inner loops are adjusted accordingly.
    for (i = 0; i < len; i += 2) {
        int16_t val = fc_in[i];
        if (val) {
            for (k = 0; k < i; k += 2)
                fc_out[k] += (val * filter[len + k - i]) >> 15;
            for (k = i; k < len; k += 2)
                fc_out[k] += (val * filter[k - i]) >> 15;
        }
    }
    // Handle remaining odd index if len is odd
    if (len % 2 && fc_in[len-1]) {
        int16_t val = fc_in[len-1];
        for (k = 0; k < len-1; k++)
            fc_out[k] += (val * filter[len + k - (len-1)]) >> 15;
        fc_out[len-1] += (val * filter[0]) >> 15;
    }
}
