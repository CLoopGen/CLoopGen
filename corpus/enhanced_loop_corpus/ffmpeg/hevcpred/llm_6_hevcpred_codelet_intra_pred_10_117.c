#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint16_t *left;
extern uint16_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 2 * size - 3; j >= 1; j--) {
        filtered_left[j] = (left[j + 1] + 2 * left[j] + left[j - 1] + 2) >> 2;
    }
    if (size > 0) {
        filtered_left[2 * size - 2] = (left[2 * size - 1] + 2 * left[2 * size - 2] + left[2 * size - 3] + 2) >> 2;
        if (size >= 2) {
            filtered_left[0] = (left[1] + 2 * left[0] + left[-1] + 2) >> 2;
        }
    }
}
