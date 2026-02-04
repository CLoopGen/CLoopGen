#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *buf;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ix = 0; ix < 4; ++ix)
        for (int j = 0; j < 4; ++j)
            buf[-(ix * 4 + j)] = '0';
}
