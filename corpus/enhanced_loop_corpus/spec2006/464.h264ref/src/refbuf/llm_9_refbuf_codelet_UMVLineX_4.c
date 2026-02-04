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
        if ((i - x) < 16) {
            line[i - x] = Picy[0];
        }
    }
}
