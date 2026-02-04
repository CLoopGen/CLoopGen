#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 2 * 32 - 2; i >= 0; i--) {
        temp = (top[i + 1] + top[i - 1] + 2) >> 1;
        filtered_top[i] = (temp + top[i] + 1) >> 1;
    }
}
