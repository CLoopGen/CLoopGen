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
    uint32_t prev_state = state;
    uint32_t current_state;
    int found = 0;
    for (i = 0; i < buf_size && !found; i++) {
        current_state = (prev_state << 8) | buf[i];
        if (current_state == 438) {
            i++;
            vop_found = 1;
            found = 1;
        }
        prev_state = current_state;
    }
    if (!found) {
        state = prev_state;
    }
}
