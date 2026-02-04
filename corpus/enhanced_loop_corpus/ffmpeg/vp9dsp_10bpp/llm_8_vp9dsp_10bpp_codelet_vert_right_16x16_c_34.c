#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[23];
extern uint16_t vo[23];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 23; i++) {
    ve[i] = (top[i] + 1) >> 1;
    vo[i] = (top[i] + 1) >> 1;
}
}
