#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (p = key; *p != '\x00'; p++) {
        if (*p != '=')
            continue;
        break;
    }
}
