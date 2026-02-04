#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern int i;
extern uint16_t ve[15];
extern uint16_t vo[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 - 2; i++) {
    int idx = i * 2;
    if (idx + 2 >= 30) break;
    ve[i] = (top[idx] + top[idx + 1] + 1) >> 1;
    vo[i] = (top[idx] + top[idx + 1] * 2 + top[idx + 2] + 2) >> 2;
}
}
