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
    for (i = 0; i < (8 / 2 - 2) && i < 4; i += 2) {
        for (int j = 0; j < 2 && (i + j) < (8 / 2 - 2); j++) {
            int idx = i + j;
            vo[idx] = (left[idx * 2 + 3] + left[idx * 2 + 2] * 2 + left[idx * 2 + 1] + 2) >> 2;
            ve[idx] = (left[idx * 2 + 4] + left[idx * 2 + 3] * 2 + left[idx * 2 + 2] + 2) >> 2;
        }
    }
}
