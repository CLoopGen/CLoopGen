#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (32 / 2 - 2) / 2; i++) {
        for (int k = 0; k < 2; k++) {
            int idx = i * 2 + k;
            if (idx < (32 / 2 - 2)) {
                vo[idx] = (left[idx * 2 + 3] + left[idx * 2 + 2] * 2 + left[idx * 2 + 1] + 2) >> 2;
                ve[idx] = (left[idx * 2 + 4] + left[idx * 2 + 3] * 2 + left[idx * 2 + 2] + 2) >> 2;
            }
        }
    }
}
