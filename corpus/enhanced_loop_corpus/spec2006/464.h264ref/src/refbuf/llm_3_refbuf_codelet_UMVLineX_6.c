#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access (traverse array from end to start)
    int offset = 0;
    for (i = maxx - 1; i >= x; i--) {
        line[offset++] = Picy[i];
    }
}
