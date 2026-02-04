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
    uint32_t local_state = state;
    int found = 0;
    for (i = 0; i < buf_size && !found; i++) {
        local_state = (local_state << 8) | buf[i];
        uint32_t check_val = (local_state & 16777200);
        if ((check_val >> 8) == 1) {
            found = 1;
        }
        for (j = 1; j < 8 && !found; j++) {
            check_val = ((local_state >> j) & 16777200);
            if ((check_val >> 8) == 1) {
                found = 1;
            }
        }
        if (found) {
            vop_found = 1;
        }
    }
    state = local_state;
}
