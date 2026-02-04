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
    for (i = 0; i < (16 / 2 - 2) / 2; i++) {
        for (int j = 0; j < 2; j++) {
            int idx = i * 2 + j;
            if (idx < (16 / 2 - 2)) {
                vo[idx] = (left[idx * 2 + 3] + left[idx * 2 + 2] * 2 + left[idx * 2 + 1] + 2) >> 2;
                ve[idx] = (left[idx * 2 + 4] + left[idx * 2 + 3] * 2 + left[idx * 2 + 2] + 2) >> 2;
            }
        }
    }
}
