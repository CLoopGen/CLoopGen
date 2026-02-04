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
    for (i = 0; i < buf_size && !vop_found; i++) {
        state = (state << 8) | buf[i];
        j = 0;
        if (((state >> j) & 16777200) == 256) {
            vop_found = 1;
        } else {
            for (j = 1; j < 8; j++) {
                if (((state >> j) & 16777200) == 256) {
                    vop_found = 1;
                    break;
                }
            }
        }
    }
}
