#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int pic_found;
extern int i;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pic_found = 0;
    for (i = 0; i < buf_size && !pic_found; i++) {
        state = (state << 8) | buf[i];
        if ((state & 0xFFFF) == 435 || (state & 0xFFFF) == 438) {
            i++;
            pic_found = 1;
        }
    }
}
