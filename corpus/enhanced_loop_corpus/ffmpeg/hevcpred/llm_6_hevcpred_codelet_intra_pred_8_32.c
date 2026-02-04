#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 2 * size - 3; j >= 0; j--) {
        filtered_top[j + 1] = (top[j + 2] + 2 * top[j + 1] + top[j] + 2) >> 2;
    }
    if (2 * size - 2 >= 0) {
        filtered_top[2 * size - 2] = (top[2 * size - 1] + 2 * top[2 * size - 2] + top[2 * size - 3] + 2) >> 2;
    }
}
