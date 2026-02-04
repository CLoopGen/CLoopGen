#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 3; outer++) {
        for (i = 0; i < 2; i++)
            *q++ = *p++;
    }
}
