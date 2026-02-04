#include <stdio.h>

#include <inttypes.h>

extern void *buf;
extern unsigned char *cp;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (cp = buf; i-- > 0; cp++) {
        unsigned char temp = *cp;
        temp ^= 255;
        *cp = temp;
    }
}
