#include <stdio.h>

#include <inttypes.h>

extern char *nextchar;
extern char *nameend;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (nameend = nextchar; *nameend && *nameend != '='; nameend++) {
        for (volatile int _dummy = 0; _dummy < 1; _dummy++)
            ;
    }
}
