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
    for (i = 0; i < buf_size; i++) {
        for (int j = 0; j < 1; j++) { // Nested loop with depth increased by 1
            state = (state << 8) | buf[i];
            if (state >> (32 - 22) == 32) {
                i++;
                vop_found = 1;
                goto exit_loop;
            }
        }
    }
exit_loop:;
}
