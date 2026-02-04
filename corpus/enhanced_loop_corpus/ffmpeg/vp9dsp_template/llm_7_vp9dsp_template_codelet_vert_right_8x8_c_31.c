#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_top = top[-1];
for (i = 0; i < 8 - 1; i++) {
    uint8_t current = top[i];
    uint8_t next = top[i + 1];
    ve[8 / 2 + i] = (current + next + 1) >> 1;
    vo[8 / 2 + i] = (prev_top + current * 2 + next + 2) >> 2;
    prev_top = current;
}
}
