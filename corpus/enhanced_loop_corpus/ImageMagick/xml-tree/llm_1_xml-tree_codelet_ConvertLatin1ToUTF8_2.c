#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (size_t i = 0; (p = content + i), *(content + i) != '\x00'; i++) {
        length += (*(content + i) & 128) != 0 ? 2 : 1;
    }
}
