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
    uint8_t temp[256];
    for (i = 0; i < 256; i++)
        temp[i] = buf[pos + i];
    for (i = 0; i < 256; i++)
        alpha[i] = 255 - temp[i];
}
