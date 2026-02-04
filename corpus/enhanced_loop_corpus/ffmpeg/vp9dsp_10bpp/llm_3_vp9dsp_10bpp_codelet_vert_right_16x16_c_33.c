#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[23];
extern uint16_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reverse traversal (still using for loop)
    for (i = (16 / 2 - 2) - 1; i >= 0; i--) {
        int idx = i * 2 + 1;
        vo[i] = (left[idx + 2] + left[idx + 1] * 2 + left[idx] + 2) >> 2;
        ve[i] = (left[idx + 3] + left[idx + 2] * 2 + left[idx + 1] + 2) >> 2;
    }
}
