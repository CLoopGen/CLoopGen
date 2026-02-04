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
    int k = j;
    for (i = 2; i < buf_size - 2 && k < buf_size + 1024 - 2; i++) {
        recoded[k] = buf[i];
        k++;
    }
    j = k;
}
