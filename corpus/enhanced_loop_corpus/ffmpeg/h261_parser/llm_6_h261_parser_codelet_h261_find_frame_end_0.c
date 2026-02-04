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
    uint32_t temp_state = state;
    for (i = 0; i < buf_size && !vop_found; i++) {
        temp_state = (temp_state << 8) | buf[i];
        for (j = 7; j >= 0; j--) {
            uint32_t masked = (temp_state >> j) & 16777200;
            if (masked == 256) {
                vop_found = 1;
                break;
            }
        }
    }
    state = temp_state;
}
