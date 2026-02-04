#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char key[4096];
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char found = 0;
    for (p = key; *p != '\x00' && !found; p++) {
        found = (*p == '=');
    }
    if (*p == '=') p--; // Adjust to point to '=' like original
}
