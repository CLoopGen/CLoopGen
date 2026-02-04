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
    for (int depth1 = 0; depth1 < buf_size; depth1++) {
        state = (state << 8) | buf[depth1];
        if (state == 435 || state == 438) {
            i = depth1 + 1;
            pic_found = 1;
            break;
        }
        for (int depth2 = 0; depth2 < 1; depth2++) { // Artificially nested with fixed iteration
            if (depth2) break; // Redundant logic to maintain structure without altering behavior
        }
    }
}
