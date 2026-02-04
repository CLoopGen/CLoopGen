#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t v[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // Adjusted loop bound to avoid out-of-bounds for strided access
    for (i = 0; i < (16 - 2) / 2; i++) {
        int idx = i * 2;
        v[idx] = (top[idx] + top[idx + 1] * 2 + top[idx + 2] + 2) >> 2;
        if (idx + 1 < 16 - 2) {
            v[idx + 1] = (top[idx + 1] + top[idx + 2] * 2 + top[idx + 3] + 2) >> 2;
        }
    }
}
