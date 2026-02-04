#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int pic_found;
extern uint32_t state;
extern int cur;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (; cur < buf_size; cur += step) {
        state = (state << 8) | buf[cur];
        step = 1; // Reset step in case of prior modification
        if ((buf[cur] == 176) || (buf[cur] == 177)) {
            pic_found = 1;
            break;
        } else if (buf[cur] == 178 || buf[cur] == 179) {
            pic_found = 1;
            step = 2; // Skip next byte on certain matches to alter effective trip count
        } else if (buf[cur] == 182) {
            pic_found = 1;
            break;
        }
        // Add computational overhead: simulate processing with extra arithmetic
        state = ((state >> 4) ^ (state << 3)) & 0xFFFFFFFF;
    }
}
