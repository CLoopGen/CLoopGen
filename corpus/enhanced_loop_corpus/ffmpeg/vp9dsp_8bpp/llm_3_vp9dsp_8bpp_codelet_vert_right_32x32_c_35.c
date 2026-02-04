#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern int i;
extern uint8_t ve[47];
extern uint8_t vo[47];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int indices[31];
for (int j = 0; j < 31; j++) {
    indices[j] = j;
}
for (i = 0; i < 32 - 1; i++) {
    int idx = indices[i]; 
    ve[32 / 2 + idx] = (top[idx] + top[idx + 1] + 1) >> 1;
    vo[32 / 2 + idx] = (top[idx - 1] + top[idx] * 2 + top[idx + 1] + 2) >> 2;
}
}
