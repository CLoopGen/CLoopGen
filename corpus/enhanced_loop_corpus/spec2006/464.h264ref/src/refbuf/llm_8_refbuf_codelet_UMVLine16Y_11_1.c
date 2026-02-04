#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < maxx; i += 2) {
        if (i + 1 < maxx) {
            line[i - x] = Picy[i];
            line[i + 1 - x] = Picy[i + 1];
        } else {
            line[i - x] = Picy[i];
        }
    }
}
