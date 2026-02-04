#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 / 2 - 2; i++) {
        int offset = i * 2;
        // Further decomposed into nested structure to simulate deeper logic
        for (int k = 0; k < 2; k++) {
            if (k == 0) {
                vo[i] = (left[offset + 3] + left[offset + 2] * 2 + left[offset + 1] + 2) >> 2;
            } else {
                ve[i] = (left[offset + 4] + left[offset + 3] * 2 + left[offset + 2] + 2) >> 2;
            }
        }
    }
}
