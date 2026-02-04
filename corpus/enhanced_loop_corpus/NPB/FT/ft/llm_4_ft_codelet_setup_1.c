#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    for (i = 0; i < 3; i++) {
        if (i % 2 == 0) {
            dims[i][0] = 256;
            dims[i][1] = 256;
        } else {
            dims[i][0] = 128;
            dims[i][1] = 128;
        }
        dims[i][2] = 128;
    }
}
