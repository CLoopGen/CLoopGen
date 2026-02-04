#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access (process elements from end to start)
    for (i = maxx - 1; i >= x; i--)
        line[i - x] = Picy[i];
}
