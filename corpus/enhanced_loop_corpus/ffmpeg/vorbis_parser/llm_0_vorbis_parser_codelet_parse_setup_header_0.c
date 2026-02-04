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
for (i = 0; i < buf_size; i++) {
    for (j = 0; j < 1; j++) {
        rev_buf[i] = buf[buf_size - 1 - i];
    }
}
}
