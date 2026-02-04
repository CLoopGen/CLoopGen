#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i;
uint16_t *left = (uint16_t*)malloc(64 * sizeof(uint16_t));
for (i = 0; i < 128; i++) {
    int idx = i % 64;
    left[idx] = ((64 - idx) * left[63] + (idx + 1) * left[0] + 32) >> 6;
}
free(left);
}
