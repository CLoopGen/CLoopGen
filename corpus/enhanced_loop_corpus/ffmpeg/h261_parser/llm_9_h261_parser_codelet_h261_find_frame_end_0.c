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
    for (i = 0; i < buf_size && !vop_found; i += 2) {
        state = (state << 8) | buf[i];
        if (i + 1 < buf_size) {
            state = (state << 8) | buf[i + 1];
        }
        for (j = 0; j < 16; j += 2) {
            if (((state >> j) & 16777200) == 256) {
                vop_found = 1;
                break;
            }
        }
    }
}
