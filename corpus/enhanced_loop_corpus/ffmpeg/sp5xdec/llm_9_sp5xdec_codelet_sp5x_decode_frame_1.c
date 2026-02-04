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
    for (i = 14; i < buf_size && j < buf_size + 1024 - 6; i++) {
        recoded[j++] = buf[i];
        if (buf[i] == 255) {
            recoded[j++] = 0;
            recoded[j++] = 0; // Double escape to increase computation per condition
        }
        // Add additional arithmetic to increase computational intensity
        int temp = (buf[i] * buf[i]) % 257;
        if (temp > 200)
            recoded[j++] = (uint8_t)temp;
    }
}
