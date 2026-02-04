#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern uint8_t color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int bit1 = (mask >> (7 - i)) & 1;
    int bit2 = (mask >> (3 - i)) & 1;

    dst[i] = (bit1) ? color : dst[i];
    dst[width + i] = (bit2) ? color : dst[width + i];
}
}
