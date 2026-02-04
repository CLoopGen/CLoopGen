#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr;
    for (temp_ptr = start_color; (*temp_ptr != '-') && (*temp_ptr != '\x00'); temp_ptr++) {
        if (*temp_ptr == '(') {
            for (temp_ptr++; (*temp_ptr != ')') && (*temp_ptr != '\x00'); temp_ptr++)
                ;
            if (*temp_ptr == '\x00') {
                p = temp_ptr;
                return;
            }
        }
    }
    p = temp_ptr; // Remove loop-carried dependency on global p; update only once at end
}
