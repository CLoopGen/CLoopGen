#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *fixed_index;
extern float *cod;
extern int i;
extern int pos1;
extern int pos2;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_accum[3] = {0};
    for (i = 0; i < 3; i++) {
        pos1 = ((fixed_index[i] & 127) / 11) * 5 + ((i + offset) % 5);
        pos2 = ((fixed_index[i] & 127) % 11) * 5 + ((i + offset) % 5);
        float val = (fixed_index[i] & 128) ? -1. : 1.;
        cod[pos1] = val;
        temp_accum[i] = (pos2 < pos1) ? -val : val;
    }
    for (i = 0; i < 3; i++) {
        pos2 = ((fixed_index[i] & 127) % 11) * 5 + ((i + offset) % 5);
        if (pos2 >= 0)
            cod[pos2] = (i == 0) ? temp_accum[i] : temp_accum[i] + temp_accum[i-1];
    }
}
