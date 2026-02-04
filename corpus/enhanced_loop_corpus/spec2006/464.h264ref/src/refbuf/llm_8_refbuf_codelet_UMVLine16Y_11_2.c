#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = x; i < maxx; i += step) {
        if (i < maxx) line[i - x] = Picy[i];
        if (i + 1 < maxx) line[i - x + 1] = Picy[i + 1];
    }
}
