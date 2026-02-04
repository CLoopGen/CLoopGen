#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t indices[24];
    for (int i = 0; i < 24; i++) {
        indices[i] = i;
    }
    for (g = 0; g < 24; g++) {
        int idx = indices[g]; // Indirect access via index array
        *pal++ = 4278190080U | ((idx * 10 + 8) << 16) | ((idx * 10 + 8) << 8) | (idx * 10 + 8);
    }
}
