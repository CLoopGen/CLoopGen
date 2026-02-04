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
    int temp_startcode = 0;
    for (i = current_pos; i < buf_size - 4; i++) {
        uint8_t b0 = buf[i];
        uint8_t b1 = buf[i + 1];
        uint8_t b2 = buf[i + 2];
        uint8_t b3 = buf[i + 3];
        uint8_t b4 = buf[i + 4];
        if (b0 == 0 && b1 == 0 && b2 == 1 && b3 == 182) {
            temp_startcode = !(b4 & 64);
            i = buf_size; // Early exit by modifying loop index (WAW on i, breaks loop)
        }
    }
    startcode_found = temp_startcode;
}
