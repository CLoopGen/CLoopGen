#include <stdio.h>

#include <inttypes.h>

extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= 10; i++) {
        *q++ = (unsigned short)(i * i + 2 * i + 1);
    }
}
