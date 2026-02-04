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
    int step = 2;
    for (i = 2 * size - 2; i >= 0; i -= step)
        filtered_top[i] = (top[i + 1] + 3 * top[i] + top[i - 1] + 4) >> 3;
}
