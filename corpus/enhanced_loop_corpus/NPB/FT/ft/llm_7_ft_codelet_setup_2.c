#include <stdio.h>

extern  int xstart[3];
extern  int ystart[3];
extern  int zstart[3];
extern  int xend[3];
extern  int yend[3];
extern  int zend[3];
extern int i;



void loop(){
    // Introduce loop-carried dependence by making each iteration depend on previous
    xstart[0] = 1;
    xend[0] = 256;
    ystart[0] = 1;
    yend[0] = 256;
    zstart[0] = 1;
    zend[0] = 128;

    for (i = 1; i < 3; i++) {
        xstart[i] = xstart[i-1] + 1;     // WAW and loop-carried RAW: current depends on prior write
        ystart[i] = ystart[i-1] + 1;
        zstart[i] = zstart[i-1] + 1;
        xend[i] = xend[i-1] + 0;         // Loop-carried dependence with no change (WAW)
        yend[i] = yend[i-1] + 0;
        zend[i] = zend[i-1] + 0;
    }
    // First iteration values are fixed, others propagate incrementally
}
