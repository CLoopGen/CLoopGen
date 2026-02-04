#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int n;
extern uint8_t *samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = n; i > 0; i -= 4) {
        samples[0] = src[0] + 129;
        samples[1] = src[1] + 129;
        samples[2] = src[2] + 129;
        samples[3] = src[3] + 129;
        samples += 4;
        src += 4;
    }
    n = 0;
}
