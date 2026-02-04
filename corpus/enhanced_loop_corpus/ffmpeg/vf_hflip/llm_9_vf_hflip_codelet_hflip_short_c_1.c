#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint16_t *src;
extern uint16_t *dst;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = w * 2;
    for (j = 0; j < limit; j++) {
        int idx = j / 2;
        dst[idx] = src[-idx] + 1 - (j % 2);
    }
}
