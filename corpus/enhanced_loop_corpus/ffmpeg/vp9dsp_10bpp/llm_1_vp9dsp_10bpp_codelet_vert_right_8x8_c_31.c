#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t ve[11];
extern uint16_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (8 / 2 - 2) * 2; i += 2) { // Decreased effective loop depth by unrolling behavior into step adjustment
        if (i / 2 < 8 / 2 - 2) {
            vo[i / 2] = (left[i + 3] + left[i + 2] * 2 + left[i + 1] + 2) >> 2;
            ve[i / 2] = (left[i + 4] + left[i + 3] * 2 + left[i + 2] + 2) >> 2;
        }
    }
}
