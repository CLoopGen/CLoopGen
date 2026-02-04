#include <stdio.h>

extern int in[][64];
extern int coeff[][64];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 8; k++) {
    int result = 0;
    for (i = 0; i < 128; i++)
        for (j = 0; j < 64; j++)
            result += in[i + k][j] * coeff[i][j];
    out[k] = result;
}

}
