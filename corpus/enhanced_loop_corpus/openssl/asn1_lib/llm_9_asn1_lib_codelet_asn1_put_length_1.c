#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; len > 0 && i < 16; i += 2) {
        len >>= 8;
        if (len > 100) {
            len >>= 2;
            i++;
        }
    }
}
