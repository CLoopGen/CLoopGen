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
    int step = 4;
    for (i = 0; i <= buf_size - step; i += step) {
        state = 0;
        for (int j = 0; j < step; j++) {
            state = (state << 8) | buf[i + j];
            if ((state >> 10) == 32) {
                i = i + j + 1;
                vop_found = 1;
                break;
            }
        }
        if (vop_found) break;
    }
    if (!vop_found) {
        for (; i < buf_size; i++) {
            state = (state << 8) | buf[i];
            if ((state >> 10) == 32) {
                i++;
                vop_found = 1;
                break;
            }
        }
    }
}
