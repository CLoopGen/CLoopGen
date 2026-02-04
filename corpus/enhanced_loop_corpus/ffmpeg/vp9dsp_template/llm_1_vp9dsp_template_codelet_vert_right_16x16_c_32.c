#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[23];
extern uint8_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (16 / 2 - 2 > 0) {
    i = 0;
    for (int level = 0; level < 1; level++) {
        while (i < 16 / 2 - 2) {
            vo[i] = (left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 2) >> 2;
            ve[i] = (left[i * 2 + 4] + left[i * 2 + 3] * 2 + left[i * 2 + 2] + 2) >> 2;
            i++;
            break;
        }
    }
}
}
