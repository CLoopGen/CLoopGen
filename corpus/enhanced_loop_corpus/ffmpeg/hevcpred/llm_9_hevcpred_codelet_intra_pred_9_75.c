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
    for (i = 2 * size - 3; i >= 1; i--)
        filtered_top[i] = (top[i + 1] + top[i + 1] + top[i] + top[i] + top[i - 1] + top[i - 1] + 4) >> 3;
}
