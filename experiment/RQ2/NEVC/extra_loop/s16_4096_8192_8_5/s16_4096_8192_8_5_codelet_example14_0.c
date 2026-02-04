#include <stdio.h>

extern int mat1[][8192];
extern int mat2[][8192];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 4096; i++)
        for (j = 0; j < 8192; j++)
            sum += mat1[i + k][j] * mat2[i][j];
    out[k] = sum;
}

}
