#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[8];
    for (i = 0; i < 8 - 2; i++) {
        temp[i] = (left[i] + left[i + 1] + 1) >> 1;
        v[i * 2] = temp[i];
        if (i > 0) {
            v[i * 2 - 1] = (temp[i-1] + temp[i] + left[i + 1] + 2) >> 2;
        }
    }
    // Final element handling to maintain coverage
    v[14 - 1] = (left[6] + left[7]*2 + left[8] + 2) >> 2;
}
