#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = start_color;
    char prev_char = '\x01';
    for (; (*temp_ptr != '-') && (*temp_ptr != '\x00'); temp_ptr++) {
        if (*temp_ptr == '(') {
            prev_char = '(';
            for (temp_ptr++; (*temp_ptr != ')') && (*temp_ptr != '\x00'); temp_ptr++) {
                prev_char = *temp_ptr;
            }
            if (*temp_ptr == '\x00') {
                break;
            }
        } else {
            prev_char = *temp_ptr;
        }
    }
    p = temp_ptr;
    if (prev_char == '\x01') p = start_color;
}
