#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *vector;
extern int i;
extern int cb_gain;
extern int cb_shift;
extern int cb_sign;
extern int cb_pos;
extern int offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        int temp_offset1 = ((cb_pos >> (i & 3)) & 7) * 8 + cb_shift + (i << 1);
        int temp_offset2 = temp_offset1 + 1;
        int sign1 = (cb_sign >> i) & 1;
        int sign2 = (cb_sign >> (i + 1)) & 1;
        vector[temp_offset1] = sign1 ? cb_gain : -cb_gain;
        vector[temp_offset2] = sign2 ? cb_gain : -cb_gain;
    }
}
