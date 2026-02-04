#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = start_color;
    char prev_char = '\0';
    for (; (temp_p[0] != '-') && (temp_p[0] != '\x00'); temp_p++) {
        if (prev_char == '(') {
            for (temp_p++; (*temp_p != ')') && (*temp_p != '\x00'); temp_p++)
                ;
            if (*temp_p == '\x00')
                break;
        }
        prev_char = *temp_p;
    }
    p = temp_p;
}
