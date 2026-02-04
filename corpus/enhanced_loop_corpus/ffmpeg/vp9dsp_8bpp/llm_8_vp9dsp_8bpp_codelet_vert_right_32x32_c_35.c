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
for (i = 0; i < 47; i++) {
    if (i + 1 < 47) {
        ve[i] = (top[i] + top[i + 1] + 1) >> 1;
    }
    if (i > 0 && i + 1 < 47) {
        vo[i] = (top[i - 1] + (top[i] << 1) + top[i + 1] + 2) >> 2;
    } else if (i == 0 && i + 1 < 47) {
        vo[i] = (top[i] + top[i + 1] + 1) >> 1;
    }
}
}
