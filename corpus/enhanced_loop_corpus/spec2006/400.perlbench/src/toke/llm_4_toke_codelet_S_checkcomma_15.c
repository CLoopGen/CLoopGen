#include <stdio.h>

#include <inttypes.h>

extern char *w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; *w; w++) {
        if ((*w) != ' ' && (*w) != '\t' && (*w) != '\n' && (*w) != '\r' && (*w) != '\f') {
            break;
        }
    }
}
