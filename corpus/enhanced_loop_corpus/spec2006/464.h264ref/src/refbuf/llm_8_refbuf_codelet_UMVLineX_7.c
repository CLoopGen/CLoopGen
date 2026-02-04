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
    int offset;
    for (i = start; i < maxx && i - x >= 0; i++) {
        offset = i - x;
        line[offset] = Picy[width - 1];
    }
}
