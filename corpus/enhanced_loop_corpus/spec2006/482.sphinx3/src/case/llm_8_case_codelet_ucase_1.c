#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char *p = cp;
    for (; *p; p++) {
        char c = *p;
        if (c >= 'a' && c <= 'z') {
            *p = c - ('a' - 'A');
        }
    }
}
