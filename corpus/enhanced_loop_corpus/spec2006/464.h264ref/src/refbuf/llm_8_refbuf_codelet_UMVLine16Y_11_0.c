#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = x; i < maxx; i += 2) {
        line[i - x] = Picy[0];
        if (i + 1 < maxx)
            line[i - x + 1] = Picy[0];
    }
}
