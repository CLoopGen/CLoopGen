#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern uint32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; ++i) {
    const int index = 7 - i;
    if (index >= 0 && index < 8) {
        uint32_t rotated = (src[i] << 16) | (src[i] >> 16);
        src[i] = rotated ^ src[index];
    }
}
}
