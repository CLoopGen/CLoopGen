#include <stdio.h>

extern int mat1[][16384];
extern int mat2[][16384];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 4; k++) {
    int sum = 0;
    for (i = 0; i < 256; i++)
        for (j = 0; j < 16384; j++)
            sum += mat1[i + k][j] * mat2[i][j];
    out[k] = sum;
}

}
