#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p;
    for (p = start_color; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            temp_p = p + 1;
            for (; (*temp_p != ')') && (*temp_p != '\x00'); temp_p++)
                ;
            if (*temp_p == '\x00') {
                p = temp_p;
                break;
            }
            p = temp_p + 1;
        } else {
            p++;
        }
    }
}
