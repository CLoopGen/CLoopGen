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
    if (buf_size <= 4) return;
    for (i = 2; i < buf_size - 2; i++) {
        recoded[j] = buf[i];
        j++;
    }
}
