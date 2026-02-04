#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern uint8_t *recoded;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 4; i < buf_size - 4 && j < buf_size + 1024 - 4; i += 2)
        recoded[j++] = buf[i], recoded[j++] = buf[i+1];
}
