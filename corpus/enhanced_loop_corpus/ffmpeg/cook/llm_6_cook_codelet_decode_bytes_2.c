#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *obuf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp;
    for (i = 0; i < bytes / 4; i++) {
        temp = buf[i];
        obuf[i] = c ^ temp;
    }
}
