#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[11];
extern uint16_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint16_t prev_top = top[-1]; 
for (i = 0; i < 8 - 1; i++) {
    uint16_t current = top[i];
    uint16_t next = top[i + 1];
    ve[4 + i] = (current + next + 1) >> 1;
    vo[4 + i] = (prev_top + current * 2 + next + 2) >> 2;
    prev_top = current;
}
}
