#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *bitmap;
extern uint16_t *lut;
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_k = k;
    for (i = 0; i < (1 << 16); i += 2) {
        // Process two iterations per loop to modify data access pattern and reduce loop-carried dependency on k
        if ((i == 0) || (bitmap[i >> 3] & (1 << (i & 7)))) {
            lut[local_k++] = i;
        }
        int next_i = i + 1;
        if (next_i < (1 << 16)) {
            if ((next_i == 0) || (bitmap[next_i >> 3] & (1 << (next_i & 7)))) {
                lut[local_k++] = next_i;
            }
        }
    }
    k = local_k; // Single write to shared k at end, reducing WAW and RAW hazards
}
