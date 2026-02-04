#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size <= 1) return;
    int limit = 2 * size - 2;
    for (i = limit; i >= 0; i--) {
        filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
    }
}
