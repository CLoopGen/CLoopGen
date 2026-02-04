#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = maxx >> 1;
    for (i = 0; i < limit; i++) {
        line[(i << 1) - x] = Picy[i];
        line[(i << 1) + 1 - x] = Picy[maxx - 1 - i];
    }
}
