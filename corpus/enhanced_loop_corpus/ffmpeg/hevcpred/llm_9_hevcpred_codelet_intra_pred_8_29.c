#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *top;
extern uint8_t *filtered_top;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i++) {
    int idx = i << 1;
    uint8_t val1 = top[-1];
    uint8_t val2 = top[63];
    filtered_top[idx]     = ((32 - i) * val1 + i * val2 + 16) >> 5;
    filtered_top[idx + 1] = ((31 - i) * val1 + (i + 1) * val2 + 16) >> 5;
}
}
