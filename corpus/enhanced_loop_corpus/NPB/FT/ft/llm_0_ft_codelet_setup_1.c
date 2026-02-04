#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 3; i++) {
            dims[i][0] = 256;
            dims[i][1] = 256;
            dims[i][2] = 128;
        }
    }
}
