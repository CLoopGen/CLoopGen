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
    uint32_t local_state = state;
    int local_vop_found = vop_found;
    int local_i = 0;
    for (; local_i < buf_size; local_i++) {
        local_state = (local_state << 8) | buf[local_i];
        if (local_state == 438) {
            local_i++;
            local_vop_found = 1;
            break;
        }
    }
    i = local_i;
    vop_found = local_vop_found;
    state = local_state;
}
