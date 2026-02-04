#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = x; i < maxx; i++) {
        if (i >= 0) {
            line[i - x] = Picy[i];
        }
    }
}
