#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern  uint8_t *scantable;
extern  int *qmat;
extern int last_non_zero;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 64; ++i) {
    int j = scantable[i];
    int val = block[j];
    int sign = (val >> (8 * sizeof(val) - 1));
    int abs_val = (val ^ sign) - sign;
    int scaled_level = (abs_val * qmat[j] + (1 << 17)) >> 18;
    int clamped_level = scaled_level < 32767 ? scaled_level : 32767;
    block[j] = (clamped_level ^ sign) - sign;
    if (clamped_level)
        last_non_zero = i;
}
}
