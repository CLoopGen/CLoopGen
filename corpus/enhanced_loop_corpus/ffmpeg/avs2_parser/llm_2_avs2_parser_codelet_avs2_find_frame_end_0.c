#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int pic_found;
extern uint32_t state;
extern int cur;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2) with bounds check
    for (; cur < buf_size; cur += 2) {
        if (cur + 1 < buf_size) {
            state = (state << 16) | (buf[cur] << 8) | buf[cur + 1];
        } else {
            state = (state << 8) | buf[cur];
        }
        if (((buf[cur]) == 176 || (buf[cur]) == 177 || (buf[cur]) == 178 || ((buf[cur]) == 179 || (buf[cur]) == 182))) {
            ++cur;
            pic_found = 1;
            break;
        }
    }
}
