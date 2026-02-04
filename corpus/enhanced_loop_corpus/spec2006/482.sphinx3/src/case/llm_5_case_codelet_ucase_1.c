#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *cp; cp++) {
        if ((*cp) >= 'a' && (*cp) <= 'z') {
            *cp = *cp - 32;
        } else {
            *cp = *cp;
        }
    }
}
