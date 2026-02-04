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
    int temp_pos1[3], temp_pos2[3];
    float temp_val[3];
    for (i = 0; i < 3; i++) {
        temp_pos1[i] = ((fixed_index[i] & 127) / 11) * 5 + ((i + offset) % 5);
        temp_pos2[i] = ((fixed_index[i] & 127) % 11) * 5 + ((i + offset) % 5);
        temp_val[i] = (fixed_index[i] & 128) ? -1. : 1.;
    }
    for (i = 0; i < 3; i++) {
        pos1 = temp_pos1[i];
        pos2 = temp_pos2[i];
        cod[pos1] = temp_val[i];
        if (pos2 < pos1)
            cod[pos2] = -cod[pos1];
        else
            cod[pos2] += cod[pos1];
    }
}
