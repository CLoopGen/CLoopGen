#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < 6 - 5; i++) {
        temp = temp + 1; // Introduce RAW dependency: temp used and defined in loop
        *p++ = temp;     // WAW with previous store if p overlaps, but here it's sequential
    }
}
