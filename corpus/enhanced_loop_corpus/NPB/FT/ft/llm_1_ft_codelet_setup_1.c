#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    for (i = 0; i < 3; i++) {
        for (int k = 0; k < 1; k++) {
            dims[i][0] = 256;
            dims[i][1] = 256;
            dims[i][2] = 128;
        }
    }
}
