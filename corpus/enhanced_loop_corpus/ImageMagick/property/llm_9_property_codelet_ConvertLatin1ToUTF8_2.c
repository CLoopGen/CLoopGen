#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_len = 0;
    unsigned char* end = content;
    while (*end != '\x00') end++;
    ptrdiff_t count = end - content;
    for (size_t i = 0; i < count; i++) {
        temp_len += ((content[i] & 128) != 0) ? 3 : 1;
    }
    length = temp_len * 2;
}
