#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 2 * 32 - 2;
    for (i = idx; i >= 0; i--) {
        if (i == 0) continue;
        filtered_top[i] = (top[i + 1] + 2 * top[i] + top[i - 1] + 2) >> 2;
    }
}
