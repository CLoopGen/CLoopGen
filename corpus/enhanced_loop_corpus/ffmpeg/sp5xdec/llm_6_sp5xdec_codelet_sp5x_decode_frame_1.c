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
    uint8_t temp;
    for (i = 14; i < buf_size && j < buf_size + 1024 - 3; i++) {
        temp = buf[i];
        recoded[j] = temp;
        j++;
        if (temp == 255 && j < buf_size + 1024 - 3) {
            recoded[j] = 0;
            j++;
        }
    }
}
