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
    uint32_t local_state = state;
    int local_pic_found = 0;
    int exit_flag = 0;
    for (i = 0; i < buf_size && !exit_flag; i++) {
        local_state = (local_state << 8) | buf[i];
        if ((local_state & 0xFFFFFF00) == 0x01B0) {  // Heuristic pattern check to reduce false matches
            if (local_state == 435 || local_state == 438) {
                i++;
                local_pic_found = 1;
                exit_flag = 1;
            }
        }
    }
    state = local_state;
    pic_found = local_pic_found;
}
