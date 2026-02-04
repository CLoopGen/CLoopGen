#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_ptr __attribute__((unused));
    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            temp_ptr = p;
            for (p++; (*p != ')') && (*p != '\x00'); p++)
                ;
            if (*p == '\x00') {
                p = temp_ptr;
                break;
            }
        } else {
            p++;
        }
    }
}
