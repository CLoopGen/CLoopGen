#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int offset = x;
    for (i = 0; i < maxx - x; i++) {
        line[i] = Picy[i + offset];
    }
}
