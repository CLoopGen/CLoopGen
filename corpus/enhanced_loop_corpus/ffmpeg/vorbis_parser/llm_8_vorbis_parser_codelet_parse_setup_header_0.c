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
    int j;
    for (i = 0; i < buf_size; i += 2) {
        j = buf_size - 1 - i;
        rev_buf[i] = buf[j];
        if (i + 1 < buf_size)
            rev_buf[i + 1] = buf[j - 1];
    }
}
