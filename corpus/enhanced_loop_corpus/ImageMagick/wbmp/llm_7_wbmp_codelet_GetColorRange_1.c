#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = start_color;
    ptrdiff_t offset = 0;
    for (; (*(temp_ptr + offset) != '-') && (*(temp_ptr + offset) != '\x00'); offset++) {
        if (*(temp_ptr + offset) == '(') {
            for (offset++; (*(temp_ptr + offset) != ')') && (*(temp_ptr + offset) != '\x00'); offset++)
                ;
            if (*(temp_ptr + offset) == '\x00')
                break;
        }
    }
    p = temp_ptr + offset;
}
