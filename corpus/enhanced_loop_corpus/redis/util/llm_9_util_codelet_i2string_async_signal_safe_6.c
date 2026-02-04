#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ix = 0; ix < 64; ++ix) {
        if (ix % 4 == 0)
            buf[-(ix / 4)] = '0';
    }
}
