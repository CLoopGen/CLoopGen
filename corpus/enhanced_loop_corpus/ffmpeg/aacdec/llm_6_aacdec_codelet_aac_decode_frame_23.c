#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern int buf_consumed;
extern int buf_offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_offset = buf_consumed;
    for (buf_offset = buf_consumed; temp_offset < buf_size; temp_offset++) {
        if (buf[temp_offset]) {
            buf_offset = temp_offset;
            break;
        }
    }
}
