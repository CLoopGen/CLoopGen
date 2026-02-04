#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char prev = '0';
    for (ix = 1; ix <= 16; ++ix) {
        buf[-ix] = prev;
        prev = prev + 1;
    }
}
