#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int pos;
extern uint8_t *alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        alpha[i] = 255 - buf[pos + i];
        if (i > 0)
            alpha[i] += (alpha[i-1] & 1); // Introduce WAW and RAW loop-carried dependency
    }
}
