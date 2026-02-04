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
    int local_i = 0;
    int found = 0;
    for (; local_i < buf_size && !found; local_i++) {
        local_state = (local_state << 8) | buf[local_i];
        if ((local_state >> 10) == 32) {
            found = 1;
            vop_found = 1;
        }
    }
    if (found) {
        i = local_i + 1;
        state = local_state;
    } else {
        i = local_i;
        state = local_state;
    }
}
