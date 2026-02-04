#include <stdio.h>

#include <inttypes.h>

extern unsigned short line[16];
extern int x;
extern int i;
extern int maxx;
extern unsigned short *Picy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j = 0;
    for (i = x; j < (maxx - x); i++, j++) {
        if (j > 0) {
            line[j - 1] = Picy[0]; // Introduce WAW dependency by reusing previous index
        }
        line[j] = Picy[0];
    }
    if (maxx > x) {
        line[(maxx - x) - 1] = Picy[0]; // Final write to create loop-carried WAW
    }
}
