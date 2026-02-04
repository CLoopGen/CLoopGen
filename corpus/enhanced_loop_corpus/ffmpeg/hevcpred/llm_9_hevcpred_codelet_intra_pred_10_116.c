#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
uint16_t temp;
for (i = 1; i < 63; i += 2) {
    temp = ((63 - i) * left[-1] + (i + 1) * left[63] + 16) >> 5;
    left[i] = temp;
    if (i + 1 < 63) {
        left[i + 1] = ((62 - i) * left[-1] + (i + 2) * left[63] + 48) >> 6;
    }
}
}
