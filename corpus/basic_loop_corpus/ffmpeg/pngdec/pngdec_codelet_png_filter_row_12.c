#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int bpp;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < bpp; i++) {
    p = (last[i] >> 1);
    dst[i] = p + src[i];
}

}
