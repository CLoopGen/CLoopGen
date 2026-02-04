#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (i = 0; i < 4096 && key[i] != '\x00'; i++) {
        if (key[i] == '=') {
            p = key + i;
            break;
        }
    }
    if (key[i] == '\x00')
        p = key + i;
}
