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
    uint16_t temp;
    for (i = 2 * size - 2; i >= 0; i -= 2) {
        temp = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
        filtered_top[i] = temp;
        if (i > 0) {
            filtered_top[i - 1] = (top[i] + 2 * top[i - 1] + top[i - 2] + 2) >> 2;
        }
    }
}
