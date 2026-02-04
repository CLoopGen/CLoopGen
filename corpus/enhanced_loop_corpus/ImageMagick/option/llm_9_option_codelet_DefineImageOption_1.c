#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *temp_p = key;
    size_t count = 0;
    for (; count < 4096 && *temp_p != '\x00'; temp_p++, count++) {
        if (*temp_p == '=' || *(temp_p + 1) == '=' || *(temp_p + 2) == '=') {
            if (*temp_p == '=') {
                break;
            }
        }
    }
    p = temp_p;
}
