#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[15];
extern uint8_t vo[15];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16 - 2; i++) {
    int idx = i;
    int next_idx = idx + 1;
    int next_next_idx = idx + 2;
    ve[idx] = (top[idx] + top[next_idx] + 1) >> 1;
    vo[idx] = (top[idx] + top[next_idx] * 2 + top[next_next_idx] + 2) >> 2;
}
}
