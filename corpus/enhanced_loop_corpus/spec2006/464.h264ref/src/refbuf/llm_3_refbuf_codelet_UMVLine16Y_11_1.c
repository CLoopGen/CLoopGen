#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward write with reverse read from Picy
    for (i = 0; i < maxx; i++) {
        line[i - x] = Picy[maxx - 1 - i];
    }
}
