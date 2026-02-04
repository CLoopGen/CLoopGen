#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_length = 0;
    unsigned char *local_p = content;
    for (; *local_p != '\x00'; local_p++) {
        temp_length += (*local_p & 128) ? 2 : 1;
    }
    length = temp_length;
}
