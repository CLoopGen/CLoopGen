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
    uint32_t temp_state = state;
    pic_found = 0;
    for (i = 0; i < buf_size - 1; i++) {
        temp_state = (temp_state << 8) | buf[i];
        uint32_t next_state = (temp_state << 8) | buf[i + 1];
        if (next_state == 435 || next_state == 438) {
            i++;
            pic_found = 1;
            break;
        }
    }
    if (pic_found) {
        state = temp_state;
    }
}
