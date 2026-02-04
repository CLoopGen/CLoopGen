#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = start_color;
    char current_char;
    for (p = temp_ptr; (current_char = *p), (current_char != '-') && (current_char != '\x00'); p++) {
        if (current_char == '(') {
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00') {
                p--;
                break;
            }
        }
    }
}
