#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; len > 1; i++) {
        len >>= 4;
        len -= 1;
    }
}
