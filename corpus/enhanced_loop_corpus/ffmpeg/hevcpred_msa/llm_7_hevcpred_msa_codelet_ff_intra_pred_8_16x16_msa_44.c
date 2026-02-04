#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp[32];
    int k;
    for (k = 2 * 16 - 2; k >= 0; k--) {
        temp[k] = (top[k + 1] + 2 * top[k] + top[k - 1] + 2) >> 2;
    }
    for (k = 2 * 16 - 2; k >= 0; k--) {
        filtered_top[k] = temp[k];
    }
}
