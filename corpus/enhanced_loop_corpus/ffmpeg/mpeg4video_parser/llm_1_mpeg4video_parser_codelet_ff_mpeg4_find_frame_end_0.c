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
    for (int outer = 0; outer < buf_size && !vop_found; outer++) {
        state = (state << 8) | buf[outer];
        if (state == 438) {
            i = outer + 1;
            vop_found = 1;
        } else {
            for (int inner = 0; inner < 1 && outer + 1 < buf_size; inner++) {
                state = (state << 8) | buf[outer + 1];
                if (state == 438) {
                    i = outer + 2;
                    vop_found = 1;
                    break;
                }
                state = (state >> 8); 
            }
        }
        if (vop_found) break;
    }
}
