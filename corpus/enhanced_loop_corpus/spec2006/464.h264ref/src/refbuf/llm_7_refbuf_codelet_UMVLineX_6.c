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
    for (i = x; i < maxx; i++, j++) {
        if (j > 0) {
            line[j - 1] = Picy[i - 1]; // Introduce WAW dependency by reusing previous index
        }
        line[j] = Picy[i];
    }
    if (maxx > x) {
        line[(maxx - x) - 1] = Picy[maxx - 1];
    }
}
