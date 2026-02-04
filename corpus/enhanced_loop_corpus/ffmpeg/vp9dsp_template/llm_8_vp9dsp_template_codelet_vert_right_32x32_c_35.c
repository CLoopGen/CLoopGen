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
for (i = 0; i < 48; i++) {
    if (i + 1 < 47) {
        ve[i] = (top[i] + top[i + 1] + 1) >> 1;
    }
    if (i >= 1 && i < 46) {
        vo[i] = (top[i - 1] + (top[i] << 1) + top[i + 1] + 2) >> 2;
    }
}
}
