#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int width;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = (width > x) ? width : x;
    int offset = -x;
    for (i = start; i < maxx; i += 2) {
        line[i + offset] = Picy[width - 1];
        line[i + offset + 1] = Picy[width - 1];
    }
}
