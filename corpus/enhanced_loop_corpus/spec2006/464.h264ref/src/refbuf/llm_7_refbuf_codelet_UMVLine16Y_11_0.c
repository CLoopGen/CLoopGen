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
    for (i = x, j = 0; i < maxx; i++, j++) {
        if (j > 0)
            line[j] = line[j-1]; // Introduce WAW and RAW loop-carried dependency
        else
            line[j] = Picy[0];
    }
}
