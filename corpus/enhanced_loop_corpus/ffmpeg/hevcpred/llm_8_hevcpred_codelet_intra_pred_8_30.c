#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 126; i += 2) {
    left[i] = ((64 - i) * left[-1] + i * left[63] + 32) >> 6;
    if (i + 1 < 126)
        left[i+1] = ((64 - (i + 1)) * left[-1] + (i + 1) * left[63] + 32) >> 6;
}
}
