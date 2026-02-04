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
for (i = 0; i < 8 / 2 - 1; i++) {
    vo[i] = (left[i * 2 + 3] + left[i * 2 + 2] + left[i * 2 + 1] + 1) >> 1;
    ve[i] = (left[i * 2 + 4] + left[i * 2 + 3] + left[i * 2 + 2] + 1) >> 1;
}
}
