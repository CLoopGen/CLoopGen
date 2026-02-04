#include <stdio.h>

extern int op1[][2048];
extern int op2[][2048];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    int sum_mul = 0;
    for (j = 0; j < 2048; j += 8) {
        sum_mul += (op1[i][j] * op2[i][j]);
    }
    out[i] = sum_mul;
}

}
