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
    for (i = 2 * size - 4; i >= 0; i -= 2)
        filtered_top[i] = (top[i + 1] + top[i] + top[i] + top[i - 1] + 2) >> 2;
}
