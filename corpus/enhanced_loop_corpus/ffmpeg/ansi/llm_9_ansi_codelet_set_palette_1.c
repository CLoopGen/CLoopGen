#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (g = 0; g < 12; g++) {
    uint32_t val = (g * 20 + 8);
    *pal++ = 4278190080U | (val << 16) | (val << 8) | val;
    *pal++ = 4278190080U | ((val + 10) << 16) | ((val + 10) << 8) | (val + 10);
}
}
