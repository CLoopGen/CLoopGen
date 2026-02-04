#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (6 + 3) * 2;
    for (i = 0; i < limit; i += 2) {
        *xi++ = 0;
        *xi++ = 0;
    }
}
