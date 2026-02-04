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
    for (i = 0; i < buf_size; i++) {
        temp_state = (temp_state << 8) | buf[i];
        if ((temp_state >> 10) == 32) {
            i++;
            vop_found = 1;
            state = temp_state;
            break;
        }
    }
    state = temp_state;
}
