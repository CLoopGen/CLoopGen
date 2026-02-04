#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < size; i++, src++) {
    uint8_t val = *src;
    if (val == 3 && i >= 2 && src[-1] == 0 && src[-2] == 0 && i + 1 < size && src[1] < 4) {
        dst[dsize++] = src[1];
        src++;
        i++;
    } else {
        dst[dsize++] = val;
    }
}
}
