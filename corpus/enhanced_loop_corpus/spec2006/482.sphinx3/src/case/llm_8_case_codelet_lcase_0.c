#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = cp;
    for (; *p; p++) {
        char c = *p;
        if (c >= 'A' && c <= 'Z') {
            *p = c + 32;
        }
    }
}
