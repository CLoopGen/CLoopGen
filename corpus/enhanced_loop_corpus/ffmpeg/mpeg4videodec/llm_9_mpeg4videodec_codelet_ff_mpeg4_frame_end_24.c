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
    int limit = buf_size - 4;
    for (i = current_pos; i < limit; i++) {
        uint8_t b0 = buf[i];
        uint8_t b1 = buf[i + 1];
        uint8_t b2 = buf[i + 2];
        uint8_t b3 = buf[i + 3];
        if (b0 == 0 && b1 == 0 && b2 == 1 && b3 == 182) {
            uint8_t b4 = buf[i + 4];
            startcode_found = (b4 & 64) ? 0 : 1;
            break;
        }
    }
}
