#include <stdio.h>

typedef long BLASLONG;

extern float *b;
extern BLASLONG i;
extern BLASLONG ii;
extern float *a01;
extern float *a02;
extern float *a03;
extern float *a04;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < i; ii++) {
        float val1 = *(a01 + 0);
        float val2 = *(a02 + 0);
        float val3 = *(a03 + 0);
        float val4 = *(a04 + 0);

        if (val1 != 0.0f || val2 != 0.0f) {
            b[0] = val1;
            b[1] = val2;
            b[2] = val3;
            b[3] = val4;
        } else {
            b[0] = b[1] = b[2] = b[3] = 0.0f;
        }

        a01++; a02++; a03++; a04++;
        b += 4;
    }
}
