#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int vop_found;
extern int i;
extern int j;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < buf_size - 3 && !vop_found; i++) {
        state = (state << 8) | buf[i];
        if (((state & 0xFFFFFF00) == 0x00000100)) {
            vop_found = 1;
        }
    }
}
