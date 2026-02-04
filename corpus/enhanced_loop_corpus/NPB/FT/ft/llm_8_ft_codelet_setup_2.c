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
    xstart[i] = 1 + i;
    ystart[i] = 1 - i;
    zstart[i] = 1 * i;
    xend[i] = 256 + i;
    yend[i] = 256 - i;
    zend[i] = 128 * (i + 1);
}
}
