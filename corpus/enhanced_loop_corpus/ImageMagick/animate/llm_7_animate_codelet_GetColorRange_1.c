#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_ptr = start_color;
    ptrdiff_t offset = 0;
    for (; (*(local_ptr + offset) != '-') && (*(local_ptr + offset) != '\x00'); offset++) {
        if (*(local_ptr + offset) == '(') {
            offset++;
            for (; (*(local_ptr + offset) != ')') && (*(local_ptr + offset) != '\x00'); offset++)
                ;
            if (*(local_ptr + offset) == '\x00') {
                break;
            }
        }
    }
    p = local_ptr + offset;
}
