#include <stdio.h>

extern int in[][256];
extern int coeff[][256];
extern int *result;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int sum = 0;
    for (i = 0; i < 128; i++)
        for (j = 0; j < 256; j++)
            sum += in[i + k][j] * coeff[i][j];
    result[k] = sum;
}

}
