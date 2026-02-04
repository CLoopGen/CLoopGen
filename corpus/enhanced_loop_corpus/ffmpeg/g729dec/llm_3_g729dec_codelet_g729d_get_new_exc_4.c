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
    // Variant 2: Reverse consecutive memory access
    // Traverse the arrays from the end to the beginning
    // This changes the access pattern to descending order,
    // which may affect cache behavior and pipeline efficiency.
    for (i = subframe_size - 1; i >= 0; i--) {
        out[i] = in[i];
        out[i] -= (gain_code * fc_cur[i] + 8192) >> 14;
        out[i] += (gain_code * fc_new[i] + 8192) >> 14;
    }
}
