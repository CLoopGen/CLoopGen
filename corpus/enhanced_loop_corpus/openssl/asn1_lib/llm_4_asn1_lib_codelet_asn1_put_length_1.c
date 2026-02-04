#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; len > 0 && i < 32; i++)
        if (len & 0xFF)
            len >>= 8;
        else
            break;
}
