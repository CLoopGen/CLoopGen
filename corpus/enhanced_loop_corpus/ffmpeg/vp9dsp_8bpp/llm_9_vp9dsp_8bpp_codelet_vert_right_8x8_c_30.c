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
for (i = 0; i < 8 / 2 - 3; i += 1) {
    int idx1 = i * 2 + 2;
    int idx2 = i * 2 + 3;
    vo[i] = (left[idx2] + left[idx1] + left[idx1 - 1] + 1) >> 1;
    ve[i] = (left[idx2 + 1] + left[idx2] + left[idx1] + 1) >> 1;
}
}
