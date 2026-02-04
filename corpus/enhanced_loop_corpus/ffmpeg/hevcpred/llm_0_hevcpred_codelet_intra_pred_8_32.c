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
    for (j = 0; j < 1; j++) {
        for (i = 2 * size - 2; i >= 0; i--)
            filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
    }
}
