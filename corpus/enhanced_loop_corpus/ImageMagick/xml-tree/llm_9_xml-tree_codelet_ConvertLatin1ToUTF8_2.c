#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  unsigned char *restrict content;
extern  unsigned char *restrict p;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t local_length = 0;
    unsigned char* end = content;
    for (; *end != '\x00'; end++);
    for (p = content; p < end; p++) {
        local_length += (*p & 128) ? 2 : 1;
        if ((*p & 32) == 0) local_length++;
    }
    length = local_length;
}
