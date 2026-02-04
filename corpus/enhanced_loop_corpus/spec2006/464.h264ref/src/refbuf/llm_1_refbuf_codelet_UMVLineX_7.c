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
    if ((((width) > (x)) ? (width) : (x)) < maxx) {
        i = (((width) > (x)) ? (width) : (x));
        for (; i < maxx; i++) {
            line[i - x] = Picy[width - 1];
        }
    }
}
