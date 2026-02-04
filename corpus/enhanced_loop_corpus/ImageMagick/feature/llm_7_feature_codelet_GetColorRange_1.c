#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr = start_color;
    char prev = '\x01';
    for (; (*temp_ptr != '-') && (*temp_ptr != '\x00') && (prev != '\x00'); temp_ptr++) {
        prev = *temp_ptr;
        if (*temp_ptr == '(') {
            for (temp_ptr++; (*temp_ptr != ')') && (*temp_ptr != '\x00'); temp_ptr++) {
                prev = *temp_ptr;
            }
            if (*temp_ptr == '\x00') {
                prev = '\x00';
                break;
            }
        }
    }
    p = (*temp_ptr == '\x00') ? temp_ptr : temp_ptr - ((*temp_ptr == '-') ? 0 : 1);
}
