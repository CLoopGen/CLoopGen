#include <stdio.h>

extern int in[][128];
extern int coeff[][128];
extern int *out;
extern int k;
extern int j;
extern int i;

void loop(){
for (k = 0; k < 4; k++) {
    int result = 0;
    for (i = 0; i < 256; i++)
        for (j = 0; j < 128; j++)
            result += in[i + k][j] * coeff[i][j];
    out[k] = result;
}

}
