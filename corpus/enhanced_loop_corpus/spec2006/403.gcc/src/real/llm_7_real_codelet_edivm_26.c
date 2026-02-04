#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short val = 0;
    for (i = 2; i < (6 + 3); i++) {
        *(p + i - 2) = val;
    }
}
