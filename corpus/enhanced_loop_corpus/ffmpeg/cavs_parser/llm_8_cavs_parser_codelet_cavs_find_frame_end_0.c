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
    for (i = 0; i < buf_size && !pic_found; i += 2) {
        if (i + 1 < buf_size) {
            state = (state << 16) | (buf[i] << 8) | buf[i + 1];
            if (state == 435 || state == 438) {
                pic_found = 1;
                break;
            }
        } else {
            state = (state << 8) | buf[i];
            if (state == 435 || state == 438) {
                pic_found = 1;
            }
        }
    }
}
