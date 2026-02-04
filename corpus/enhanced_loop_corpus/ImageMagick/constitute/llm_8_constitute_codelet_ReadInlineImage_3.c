#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *content;
extern  char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t offset = 0;
    char c;
    for (p = content; ((c = *(content + offset)) != '/') && (c != '\x00'); offset++)
        ;
    p = content + offset;
}
