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
    int limit = (maxx - x) < 16 ? (maxx - x) : 16;
    for (i = 0; i < limit; i++) {
        line[i] = Picy[width - 1];
    }
}
