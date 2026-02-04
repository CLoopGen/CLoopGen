#include <stdio.h>

extern int in[][512];
extern int coeff[][512];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int result = 0;
    for (i = 0; i < 512; i++)
        for (j = 0; j < 512; j++)
            result += in[i + k][j] * coeff[i][j];
    out[k] = result;
}

}
