#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int g;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (g = 0; g < 48; g += 2)
    *pal++ = 4278190080U | ((g * 5 + 8) << 16) | ((g * 5 + 8) << 8) | (g * 5 + 8);
}
