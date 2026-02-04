#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2 * 16 - 4; i >= 0; i--)
    filtered_top[i] = (top[i + 2] + 3 * top[i + 1] + 3 * top[i] + top[i - 1] + top[i - 2] + 4) >> 3;
}
