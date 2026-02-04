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
    for (i = 0; i < 128; i++) {
        alpha[i] = 255 - buf[pos + i * 2];
        alpha[255 - i] = 255 - buf[pos + i * 2 + 1];
    }
}
