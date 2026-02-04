#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 - 1; i++) {
        if (i >= 1) {
            ve[8 / 2 + i] = (top[i] + top[i + 1] + 1) >> 1;
            vo[8 / 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
        } else {
            ve[8 / 2 + i] = 0;
            vo[8 / 2 + i] = (top[i] + 1) >> 1;
        }
    }
}
