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
    for (int depth1 = 0; depth1 < buf_size; depth1++) {
        state = (state << 8) | buf[depth1];
        if (state == 438) {
            i = depth1 + 1;
            vop_found = 1;
            break;
        }
        for (int depth2 = 0; depth2 < 1; depth2++) {
            if (depth2) break;
        }
    }
}
