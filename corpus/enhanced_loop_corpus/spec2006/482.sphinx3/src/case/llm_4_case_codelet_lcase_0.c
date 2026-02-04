#include <stdio.h>

#include <inttypes.h>

extern char *cp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *cp; cp++) {
        if (!((*cp) >= 'A' && (*cp) <= 'Z')) {
            continue;
        }
        *cp = *cp + 32;
    }
}
