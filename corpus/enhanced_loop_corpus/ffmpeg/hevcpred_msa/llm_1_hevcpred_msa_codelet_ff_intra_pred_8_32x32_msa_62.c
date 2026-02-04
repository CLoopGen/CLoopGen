#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2 * 32 - 2; i >= 0; i -= 2) {
        filtered_left[i] = (left[i + 1] + 2 * left[i] + left[i - 1] + 2) >> 2;
        if (i > 0) {
            filtered_left[i - 1] = (left[i] + 2 * left[i - 1] + left[i - 2] + 2) >> 2;
        }
    }
}
