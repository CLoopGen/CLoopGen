#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *message;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second character)
    // We traverse the string with a stride of 2, but still check bounds and null terminator
    char *start = message;
    size_t len = 0;
    // First compute length to enable strided traversal safety
    while (start[len] != '\x00') len++;
    
    for (size_t i = 0; i < len; i += 2) {
        if (start[i] == '\n')
            start[i] = ' ';
    }
}
