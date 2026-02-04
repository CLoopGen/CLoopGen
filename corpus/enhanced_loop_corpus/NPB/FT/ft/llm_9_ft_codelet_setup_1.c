#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    for (i = 0; i < 6; i++) {
        int j = i % 3;
        dims[j][0] = 256;
        dims[j][1] = 256;
        dims[j][2] = 128;
    }
}
