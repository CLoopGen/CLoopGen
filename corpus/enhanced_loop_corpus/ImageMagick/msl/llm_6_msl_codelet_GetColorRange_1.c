#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = start_color;
    char prev_char = '\0';
    for (; (*local_p != '-') && (*local_p != '\x00'); local_p++) {
        if (*local_p == '(') {
            prev_char = '(';
            for (local_p++; (*local_p != ')') && (*local_p != '\x00'); local_p++)
                prev_char = *local_p;
            if (*local_p == '\x00') {
                local_p--;
                break;
            }
        } else {
            prev_char = *local_p;
        }
    }
    p = local_p;
}
