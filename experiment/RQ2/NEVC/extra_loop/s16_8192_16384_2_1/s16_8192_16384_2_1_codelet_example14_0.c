#include <stdio.h>

extern int in[][16384];
extern int coeff[][16384];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 2; k++) {
    int result = 0;
    for (i = 0; i < 8192; i++)
        for (j = 0; j < 16384; j++)
            result += in[i + k][j] * coeff[i][j];
    out[k] = result;
}

}
