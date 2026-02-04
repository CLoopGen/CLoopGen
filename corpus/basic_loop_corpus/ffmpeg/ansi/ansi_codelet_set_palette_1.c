#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int g;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (g = 0; g < 24; g++)
    *pal++ = 4278190080U | (((g) * 10 + 8) << 16) | (((g) * 10 + 8) << 8) | ((g) * 10 + 8);

}
