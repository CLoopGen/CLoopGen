#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    unsigned char val;
    length = 0;
    for (i = 0; (val = content[i]) != '\x00'; i++) {
        length += (val & 128) ? 2 : 1;
    }
}
