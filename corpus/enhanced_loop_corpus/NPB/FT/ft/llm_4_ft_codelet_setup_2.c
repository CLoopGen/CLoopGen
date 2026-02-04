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
        if (i % 2 == 0) {
            xstart[i] = 1;
            ystart[i] = 1;
            zstart[i] = 1;
        } else {
            xstart[i] = 1;
            ystart[i] = 1;
        }
        xend[i] = 256;
        yend[i] = 256;
        zend[i] = 128;
    }
}
