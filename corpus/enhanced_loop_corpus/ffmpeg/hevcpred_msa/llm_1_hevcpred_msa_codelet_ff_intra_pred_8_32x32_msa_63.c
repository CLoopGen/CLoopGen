#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2 * 32 - 2; i >= 0; i -= 2) {
        filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
        if (i > 0) {
            filtered_top[i - 1] = (top[i] + 2 * top[i - 1] + top[i - 2] + 2) >> 2;
        }
    }
}
