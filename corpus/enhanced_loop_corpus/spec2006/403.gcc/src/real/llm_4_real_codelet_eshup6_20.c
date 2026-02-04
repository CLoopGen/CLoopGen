#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3) - 1; i++) {
        if (i % 2 == 0) {
            *p++ = *x++;
        } else {
            continue;
        }
    }
}
