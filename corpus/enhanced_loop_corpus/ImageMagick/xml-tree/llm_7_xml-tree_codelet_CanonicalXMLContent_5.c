#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *p;
extern unsigned char *utf8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char *temp_ptr = utf8;
    unsigned char val;
    ptrdiff_t offset = 0;
    for (; *(temp_ptr + offset) != '\x00'; offset++) {
        val = *(temp_ptr + offset);
        if ((val < 32) && (val != 9) && (val != 10) && (val != 13)) {
            break;
        }
    }
    p = temp_ptr + offset;
}
