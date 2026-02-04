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
    for (i = 0; i < 256; i += 4) {
        alpha[i]     = 255 - buf[pos + i];
        alpha[i + 1] = 255 - buf[pos + i + 1];
        alpha[i + 2] = 255 - buf[pos + i + 2];
        alpha[i + 3] = 255 - buf[pos + i + 3];
    }
}
