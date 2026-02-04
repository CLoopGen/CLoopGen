#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 7; i++) {
        for (int j = 0; j < 9; j++) {
            int idx = i * 9 + j;
            if (idx < 63)
                filtered_top[idx] = ((64 - (idx + 1)) * top[-1] + (idx + 1) * top[63] + 32) >> 6;
        }
    }
}
