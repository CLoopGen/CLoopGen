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
    ptrdiff_t total_steps = end - content;
    for (ptrdiff_t i = 0; i < total_steps; i++) {
        unsigned char val = content[i];
        temp_len += (val & 128) ? ((val & 64) ? 3 : 2) : 1;
    }
    length = temp_len;
}
