#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern  uint8_t *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 4; i++) {
    if (mask & (1 << 7 - i))
        dst[i] = src[i];
    if (mask & (1 << 3 - i))
        dst[width + i] = src[width + i];
}

}
