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
    for (i = 0; i < bytes / 4; ++i) {
        obuf[i] = (i % 2 == 0) ? (c ^ buf[i]) : buf[i];
    }
}
