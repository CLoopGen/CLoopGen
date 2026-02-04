#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char start_color[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *local_p = start_color;
    int found = 0;
    for (; !found && (*local_p != '-') && (*local_p != '\x00'); local_p++) {
        if (*local_p == '(') {
            for (local_p++; (*local_p != ')') && (*local_p != '\x00'); local_p++)
                ;
            if (*local_p == '\x00')
                break;
        }
        if (*(local_p - 1) == '(' && *local_p != '\x00')
            found = 1;
    }
    p = local_p;
}
