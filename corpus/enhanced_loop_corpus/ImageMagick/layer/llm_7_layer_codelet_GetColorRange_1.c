#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p;
    int found_paren = 0;
    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            found_paren = 1;
            temp_p = p;
            for (temp_p++; (*temp_p != ')') && (*temp_p != '\x00'); temp_p++)
                ;
            if (*temp_p == '\x00') {
                break;
            }
            p = temp_p + 1;
        } else {
            p++;
        }
    }
    if (!found_paren && *p != '\x00') {
        p++;
    }
}
