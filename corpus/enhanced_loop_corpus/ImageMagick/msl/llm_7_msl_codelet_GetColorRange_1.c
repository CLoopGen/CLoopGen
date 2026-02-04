#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = start_color;
    int has_unmatched_paren = 0;
    for (p = temp_p; (*p != '-') && (*p != '\x00'); ) {
        if (*p == '(') {
            has_unmatched_paren = 1;
            p++;
            while ((*p != ')') && (*p != '\x00')) {
                p++;
            }
            if (*p == '\x00') {
                has_unmatched_paren = 0;
                break;
            }
        } else {
            p++;
        }
    }
    if (has_unmatched_paren && *p == ')') {
        p++;
    }
}
