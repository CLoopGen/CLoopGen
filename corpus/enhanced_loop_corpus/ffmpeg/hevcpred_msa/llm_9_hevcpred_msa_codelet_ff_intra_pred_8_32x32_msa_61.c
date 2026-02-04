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
    uint8_t val1 = (top[-1] + top[63]) >> 1;
    uint8_t val2 = (top[-1] * 3 + top[63]) >> 2;
    filtered_top[2*i]     = (val1 + (i % 5 == 0 ? 1 : 0)) & 0xFF;
    filtered_top[2*i + 1] = (val2 + ((i + 1) % 7 == 0 ? 2 : 0)) & 0xFF;
}
}
