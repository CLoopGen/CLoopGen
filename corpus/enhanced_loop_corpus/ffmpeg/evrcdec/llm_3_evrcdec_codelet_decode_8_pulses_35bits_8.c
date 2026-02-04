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
    // Variant 2: Strided memory access — scale indices by a stride factor (e.g., 2) to simulate non-unit stepping
    const int stride = 2;
    for (i = 0; i < 3; i++) {
        int raw = fixed_index[i] & 127;
        pos1 = ((raw / 11) * 5 + ((i + offset) % 5)) * stride;
        pos2 = ((raw % 11) * 5 + ((i + offset) % 5)) * stride;
        float contribution = (fixed_index[i] & 128) ? -1.0f : 1.0f;
        cod[pos1] = contribution;
        if (pos2 < pos1) {
            cod[pos2] = -contribution;
        } else {
            cod[pos2] += contribution;
        }
    }
}
