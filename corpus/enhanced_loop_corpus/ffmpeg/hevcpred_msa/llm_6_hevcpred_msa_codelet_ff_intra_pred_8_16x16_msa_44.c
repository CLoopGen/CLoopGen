#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 2 * 16 - 2; j >= 2; j -= 2) {
        filtered_top[j] = (top[j + 1] + 2 * top[j] + top[j - 1] + 2) >> 2;
        filtered_top[j - 1] = (top[j] + 2 * top[j - 1] + top[j - 2] + 2) >> 2;
    }
    if (j == 0) {
        filtered_top[0] = (top[1] + 2 * top[0] + top[-1] + 2) >> 2;
    }
}
