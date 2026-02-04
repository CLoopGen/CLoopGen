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
    int indices[3] = {i, i + 1, i + 2};
    ve[i] = (top[indices[0]] + top[indices[1]] + 1) >> 1;
    vo[i] = (top[indices[0]] + top[indices[1]] * 2 + top[indices[2]] + 2) >> 2;
}
}
