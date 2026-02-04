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
for (int depth = 0; depth < 2; depth++) {
    for (i = 0; i < 3; i++) {
        pos1 = ((fixed_index[i] & 127) / 11) * 5 + ((i + offset + depth) % 5);
        pos2 = ((fixed_index[i] & 127) % 11) * 5 + ((i + offset + depth) % 5);
        cod[pos1] = (fixed_index[i] & 128) ? -1. : 1.;
        if (pos2 < pos1)
            cod[pos2] = -cod[pos1];
        else
            cod[pos2] += cod[pos1];
    }
}
}
