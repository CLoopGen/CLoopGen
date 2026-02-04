#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 7; i++) {
    int j;
    for (j = 0; j < 9; j++) {
        int idx = i * 9 + j;
        if (idx < 63)
            left[idx] = ((64 - (idx + 1)) * left[-1] + (idx + 1) * left[63] + 32) >> 6;
    }
}
}
