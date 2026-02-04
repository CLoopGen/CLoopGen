#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int vop_found;
extern int i;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint32_t temp_state = state;
    int limit = buf_size - 7;
    for (i = 0; i < limit; i++) {
        temp_state = (temp_state << 8) | buf[i];
        if ((temp_state & 0xFFFFFF) == 438) {
            i++;
            vop_found = 1;
            state = temp_state;
            break;
        }
    }
    if (!vop_found) {
        for (; i < buf_size; i++) {
            state = (state << 8) | buf[i];
            if (state == 438) {
                i++;
                vop_found = 1;
                break;
            }
        }
    }
}
