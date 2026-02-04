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
    // Variant 1: Consecutive memory access with array indexing rearranged for sequential cod writes
    int base_pos = (offset % 5);
    for (i = 0; i < 3; i++) {
        int idx = fixed_index[i] & 127;
        pos1 = (idx / 11) * 5 + ((i + offset) % 5);
        pos2 = (idx % 11) * 5 + base_pos;  // Make pos2 use constant offset base
        float val = (fixed_index[i] & 128) ? -1.0f : 1.0f;
        cod[pos1] = val;
        if (pos2 < pos1) {
            cod[pos2] = -val;
        } else {
            cod[pos2] += val;
        }
    }
}
