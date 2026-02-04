#include <stdio.h>

extern  int xstart[3];
extern  int ystart[3];
extern  int zstart[3];
extern  int xend[3];
extern  int yend[3];
extern  int zend[3];
extern int i;



void loop(){
    for (i = 0; i < 3; i++) {
        int idx = i;
        xstart[idx] = 1;
        xend[idx] = 256;
        ystart[idx] = 1;
        yend[idx] = 256;
        zstart[idx] = 1;
        zend[idx] = 128;
    }
}
