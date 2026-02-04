#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = start_color;
    char current;
    for (p = start_color; (current = *temp_ptr, *p != '-') && (current != '\x00'); temp_ptr++, p++) {
        if (current == '(') {
            temp_ptr++;
            p++;
            for (; (current = *temp_ptr, *p != ')') && (current != '\x00'); temp_ptr++, p++)
                ;
            if (current == '\x00') {
                p--;
                break;
            }
        }
    }
}
