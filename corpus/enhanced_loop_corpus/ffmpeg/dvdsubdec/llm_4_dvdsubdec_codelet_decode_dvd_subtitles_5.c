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
        if ((buf[pos + i] & 1) == 0) {
            alpha[i] = 255 - buf[pos + i];
        } else {
            alpha[i] = 0;
        }
    }
}
