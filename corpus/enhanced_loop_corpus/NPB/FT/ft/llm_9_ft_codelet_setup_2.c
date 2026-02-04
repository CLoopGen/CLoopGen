#include <stdio.h>

extern  int xstart[3];
extern  int ystart[3];
extern  int zstart[3];
extern  int xend[3];
extern  int yend[3];
extern  int zend[3];
extern int i;



void loop(){
for (i = 0; i < 6; i++) {
    int idx = i / 2;
    if (idx < 3) {
        xstart[idx] = 1;
        ystart[idx] = 1;
        zstart[idx] = 1;
        xend[idx] = (i % 2 == 0) ? 256 : 257;
        yend[idx] = (i % 2 == 0) ? 256 : 255;
        zend[idx] = 128;
    }
}
}
