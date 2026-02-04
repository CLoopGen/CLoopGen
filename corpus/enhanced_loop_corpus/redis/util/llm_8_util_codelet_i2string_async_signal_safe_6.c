#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ix = 0; ix < 32; ix += 2) {
        buf[-ix] = '0';
        buf[-(ix + 1)] = '0';
    }
}
