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
    uint16_t temp1, temp2;
    for (i = 2 * size - 3; i >= 1; i--) {
        temp1 = left[i + 1] + left[i];
        temp2 = left[i] + left[i - 1];
        filtered_left[i] = (temp1 + temp2 + 2) >> 2;
    }
}
