#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t **src;
extern int channels;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    uint8_t *temp_ptr;
    for (i = 3; i < 64; i++) {
        temp_ptr = src[i];
        if (!temp_ptr) break;
    }
    channels = i;
}
