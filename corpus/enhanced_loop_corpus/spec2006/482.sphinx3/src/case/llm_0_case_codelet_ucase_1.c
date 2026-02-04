#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *cp; cp++) {
        char c = *cp;
        if ((c >= 'a') && (c <= 'z')) {
            for (int i = 0; i < 1; i++) {
                *cp = c - 32;
            }
        } else {
            *cp = c;
        }
    }
}
