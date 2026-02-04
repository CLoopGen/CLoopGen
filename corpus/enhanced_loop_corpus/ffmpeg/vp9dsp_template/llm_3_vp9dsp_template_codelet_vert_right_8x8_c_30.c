#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t ve[11];
extern uint8_t vo[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *l = left + 1;
    for (i = 0; i < 8 / 2 - 2; i++) {
        vo[i] = (l[i*2+2] + l[i*2+1]*2 + l[i*2] + 2) >> 2;
        ve[i] = (l[i*2+3] + l[i*2+2]*2 + l[i*2+1] + 2) >> 2;
    }
}
