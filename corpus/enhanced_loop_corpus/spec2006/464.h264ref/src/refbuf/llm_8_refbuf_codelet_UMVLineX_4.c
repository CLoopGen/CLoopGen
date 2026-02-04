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
    for (i = x; i < maxx && (i - x) < 16; i++) {
        line[i - x] = Picy[0] + (Picy[0] >> 4);
        line[i - x] ^= (unsigned short)(i * 31);
    }
}
