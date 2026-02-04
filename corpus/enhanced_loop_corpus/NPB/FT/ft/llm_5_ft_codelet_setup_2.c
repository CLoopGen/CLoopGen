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
        xstart[i] = 1;
        xend[i] = 256;
        if (i > 0) {
            ystart[i] = 1;
            yend[i] = 256;
        }
        zstart[i] = 1;
        zend[i] = 128;
    }
}
