#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (6 - 5) * 3; i++) {
        if (i % 3 == 0)
            *p++ = 0;
    }
}
