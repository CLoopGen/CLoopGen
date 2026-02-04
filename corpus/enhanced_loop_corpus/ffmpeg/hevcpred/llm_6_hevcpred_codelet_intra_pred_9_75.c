#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 2 * size - 3; j >= 0; j--) {
        filtered_top[j] = (top[j + 1] + 2 * top[j] + top[j - 1] + 2) >> 2;
        if (j < 2 * size - 2)
            filtered_top[j + 1] += top[j + 2] >> 4;  // Introduce WAW and RAW dependency: write after write on filtered_top, read after write on top
    }
    if (2 * size - 2 >= 0)
        filtered_top[2 * size - 2] = (top[2 * size - 1] + 2 * top[2 * size - 2] + top[2 * size - 3] + 2) >> 2;
}
