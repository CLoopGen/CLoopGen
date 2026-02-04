#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int current_pos;
extern int startcode_found;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = current_pos; i < buf_size - 4; i++) {
        uint8_t b0 = buf[i], b1 = buf[i+1], b2 = buf[i+2];
        if (!(b0 | b1 | (b2 ^ 1))) {
            if (buf[i + 3] == 182) {
                startcode_found = !(buf[i + 4] & 64);
                break;
            }
        }
    }
}
