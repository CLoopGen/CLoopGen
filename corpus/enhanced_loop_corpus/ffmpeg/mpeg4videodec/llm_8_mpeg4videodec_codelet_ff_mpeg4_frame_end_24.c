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
    int step = 2;
    for (i = current_pos; i < buf_size - 4; i += step) {
        if (i + 4 < buf_size && buf[i] == 0 && buf[i + 1] == 0 && buf[i + 2] == 1 && buf[i + 3] == 182) {
            startcode_found = !(buf[i + 4] & 64);
            break;
        }
    }
}
