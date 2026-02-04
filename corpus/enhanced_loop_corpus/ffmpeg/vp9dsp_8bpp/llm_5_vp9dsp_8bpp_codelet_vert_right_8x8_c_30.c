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
        if (!(left[i * 2 + 1] & 0x1)) {
            vo[i] = (left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 2) >> 2;
        } else {
            vo[i] = left[i * 2 + 2];
        }
        if ((left[i * 2 + 2] + left[i * 2 + 3]) > 128) {
            ve[i] = 255;
        } else {
            ve[i] = (left[i * 2 + 4] + left[i * 2 + 3] * 2 + left[i * 2 + 2] + 2) >> 2;
        }
    }
}
