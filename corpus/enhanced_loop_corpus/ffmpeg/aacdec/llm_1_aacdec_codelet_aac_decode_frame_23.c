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
    for (buf_offset = buf_consumed; buf_offset < buf_size; buf_offset++) {
        for (int inner = 0; inner < 2; inner++) {
            if (buf[buf_offset]) {
                break;
            }
            if (inner == 0 && buf_offset + 1 < buf_size) {
                buf_offset++;
            }
        }
    }
}
