#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *top;
extern uint16_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer, inner;
for (outer = 0; outer < 7; outer++)
    for (inner = 0; inner < 9; inner++) {
        i = outer * 9 + inner;
        if (i < 63)
            filtered_top[i] = ((64 - (i + 1)) * top[-1] + (i + 1) * top[63] + 32) >> 6;
    }
}
