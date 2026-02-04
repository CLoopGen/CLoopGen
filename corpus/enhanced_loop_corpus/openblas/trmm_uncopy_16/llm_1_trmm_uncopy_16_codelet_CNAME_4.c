#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 1; ii++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                b[0] = *(a01 + 0);
                b[1] = *(a02 + 0);
                b[2] = *(a03 + 0);
                b[3] = *(a04 + 0);
                a01++;
                a02++;
                a03++;
                a04++;
                b += 4;
            }
        }
    }
}
