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
    uint32_t mask1 = c ^ 0xAAAAAAAA;
    uint32_t mask2 = c ^ 0x55555555;
    int limit = bytes / 4;
    for (i = 0; i < limit; i++) {
        if (i & 1) {
            obuf[i] = buf[i] ^ mask1;
        } else {
            obuf[i] = buf[i] ^ mask2;
        }
    }
}
