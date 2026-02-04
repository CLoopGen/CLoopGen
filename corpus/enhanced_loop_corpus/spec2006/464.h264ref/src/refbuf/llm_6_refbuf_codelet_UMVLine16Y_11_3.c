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
    unsigned short temp = Picy[width - 1];
    for (j = (((width) > (x)) ? (width) : (x)); j < maxx; j++) {
        line[j - x] = temp;
    }
}
