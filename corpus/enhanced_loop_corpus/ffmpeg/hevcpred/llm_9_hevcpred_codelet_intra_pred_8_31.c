#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern uint8_t *left;
extern uint8_t *filtered_left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2 * size - 3; i >= 1; i--) {
    uint16_t sum = (uint16_t)left[i + 1] + (uint16_t)left[i] + (uint16_t)left[i] + (uint16_t)left[i - 1] + 3;
    filtered_left[i] = (sum + (sum & 2)) >> 2;
}
}
