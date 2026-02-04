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
    for (i = 0; i < buf_size - 3; i += 4) {
        state = (state << 8) | buf[i];
        if (state == 438) {
            i++;
            vop_found = 1;
            break;
        }
        if (i + 1 < buf_size) {
            state = (state << 8) | buf[i + 1];
            if (state == 438) {
                i += 2;
                vop_found = 1;
                break;
            }
        }
        if (i + 2 < buf_size) {
            state = (state << 8) | buf[i + 2];
            if (state == 438) {
                i += 3;
                vop_found = 1;
                break;
            }
        }
        if (i + 3 < buf_size) {
            state = (state << 8) | buf[i + 3];
            if (state == 438) {
                i += 4;
                vop_found = 1;
                break;
            }
        }
    }
}
