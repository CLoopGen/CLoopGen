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
    // Variant 1: Strided memory access with stride of 2
    for (i = 14; i < buf_size && j < buf_size + 1024 - 3; i += 2) {
        recoded[j++] = buf[i];
        if (i + 1 < buf_size && buf[i] == 255) {
            recoded[j++] = 0;
        }
        // Handle potential overflow from last element if i+1 was needed
        if (i + 1 >= buf_size && buf[i] == 255 && j < buf_size + 1024 - 3) {
            recoded[j++] = 0;
        }
    }
}
