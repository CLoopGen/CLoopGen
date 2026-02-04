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
for (i = 0; i < 32 - 1; i++) {
    int idx = i * 2; // Strided access with step 2
    if (idx + 1 < 47) {
        ve[32 / 2 + i] = (top[idx] + top[idx + 1] + 1) >> 1;
        vo[32 / 2 + i] = (top[idx - 1] + top[idx] * 2 + top[idx + 1] + 2) >> 2;
    }
}
}
