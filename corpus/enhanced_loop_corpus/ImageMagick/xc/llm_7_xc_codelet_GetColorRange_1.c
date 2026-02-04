#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = p;
    char current;
    for (; temp_ptr < start_color + 4096; temp_ptr++) {
        current = *temp_ptr;
        if (current == '\x00' || current == '-') {
            break;
        }
        if (current == '(') {
            for (temp_ptr++; temp_ptr < start_color + 4096; temp_ptr++) {
                current = *temp_ptr;
                if (current == ')' || current == '\x00') {
                    break;
                }
            }
            if (current == '\x00') {
                break;
            }
        }
    }
    p = temp_ptr;
}
