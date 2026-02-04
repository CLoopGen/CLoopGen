#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern uint8_t *rev_buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset;
    for (i = 0; i < buf_size * 2; i++) {
        offset = i < buf_size ? i : 2 * buf_size - 1 - i;
        if (i < buf_size)
            rev_buf[offset] = buf[buf_size - 1 - offset];
        else
            rev_buf[offset] = rev_buf[offset]; // Redundant assignment to increase computation
    }
}
