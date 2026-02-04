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
        ystart[i] = xstart[i];      // RAW dependency: ystart[i] depends on xstart[i]
        zstart[i] = ystart[i];      // RAW dependency: zstart[i] depends on ystart[i]
        xend[i] = 256;
        yend[i] = xend[i];          // RAW dependency: yend[i] depends on xend[i]
        zend[i] = yend[i] / 2;      // RAW dependency: zend[i] depends on yend[i]
    }
}
