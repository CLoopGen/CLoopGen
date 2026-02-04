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
    while (1) {
        unsigned char val = *local_p;
        if (val == '\x00') break;
        temp_length += (val & 128) ? 2 : 1;
        local_p++;
    }
    length = temp_length;
}
