#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pixel;
extern uint8_t *out_buf;
extern uint8_t count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp = count;
    for (i = 0; i < temp; i++) {
        out_buf[i] = pixel;
    }
}
