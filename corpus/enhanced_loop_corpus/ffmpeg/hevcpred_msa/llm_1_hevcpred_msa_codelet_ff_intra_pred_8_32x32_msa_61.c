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
    int base = i * 9;
    for (int k = 0; k < 9 && (base + k) < 63; k++) {
        int idx = base + k;
        filtered_top[idx] = ((63 - idx) * top[-1] + (idx + 1) * top[63] + 32) >> 6;
    }
}
}
