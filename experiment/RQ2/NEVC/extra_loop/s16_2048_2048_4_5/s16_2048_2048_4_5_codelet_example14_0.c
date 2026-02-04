#include <stdio.h>

extern int mat1[][2048];
extern int mat2[][2048];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 4; k++) {
    int sum = 0;
    for (i = 0; i < 2048; i++)
        for (j = 0; j < 2048; j++)
            sum += mat1[i + k][j] * mat2[i][j];
    out[k] = sum;
}

}
