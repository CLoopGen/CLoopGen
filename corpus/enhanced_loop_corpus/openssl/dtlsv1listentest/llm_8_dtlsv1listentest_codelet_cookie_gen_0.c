#include <stdio.h>

#include <inttypes.h>

extern unsigned char *cookie;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 40; i += 2, cookie++) {
        *cookie = i / 2;
        *(cookie + 1) = i / 2 + 1;
    }
}
