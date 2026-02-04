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
for (i = 0; i < 3; i++) {
    int idx = fixed_index[i] & 127;
    int sign_bit = fixed_index[i] & 128;
    int base_offset = (i + offset) % 5;
    pos1 = (idx / 11) * 5 + base_offset;
    pos2 = (idx % 11) * 5 + base_offset;
    float val = sign_bit ? -1.0f : 1.0f;
    cod[pos1] = val;
    cod[pos2] = (pos2 < pos1) ? -val : cod[pos2] + val;
}
}
