#include <stdio.h>

extern int op1[][4096];
extern int op2[][4096];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    int sum_mul = 0;
    for (j = 0; j < 4096; j += 8) {
        sum_mul += (op1[i][j] * op2[i][j]);
    }
    out[i] = sum_mul;
}

}
