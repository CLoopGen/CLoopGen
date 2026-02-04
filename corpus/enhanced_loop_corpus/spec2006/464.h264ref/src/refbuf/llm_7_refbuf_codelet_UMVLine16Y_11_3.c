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
    int j;
    for (j = (((width) > (x)) ? (width) : (x)); j < maxx; j++) {
        if (j > (((width) > (x)) ? (width) : (x))) {
            line[j - x] = line[j - x - 1]; // Introduce loop-carried dependence (WAW + RAW)
        } else {
            line[j - x] = Picy[width - 1];
        }
    }
}
