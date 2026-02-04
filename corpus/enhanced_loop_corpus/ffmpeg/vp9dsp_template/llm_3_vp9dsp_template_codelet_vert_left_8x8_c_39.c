#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[7];
extern uint8_t vo[7];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 - 2; i++) {
    int idx0 = i;
    int idx1 = i + 1;
    int idx2 = i + 2;
    ve[i] = (top[idx0] + top[idx1] + 1) >> 1;
    vo[i] = (top[idx0] + top[idx1] * 2 + top[idx2] + 2) >> 2;
}
}
