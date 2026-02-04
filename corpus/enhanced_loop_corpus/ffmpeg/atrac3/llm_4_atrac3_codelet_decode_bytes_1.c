#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int bytes;
extern int i;
extern uint32_t c;
extern  uint32_t *buf;
extern uint32_t *output;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < bytes / 4; i++) {
        if ((c & 0x1) == 1) {
            output[i] = c ^ buf[i];
        } else {
            output[i] = buf[i];
        }
    }
}
