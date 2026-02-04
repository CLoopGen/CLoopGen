#include <stdio.h>

extern int op1[][512];
extern int op2[][512];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    int sum_add = 0;
    for (j = 0; j < 512; j += 8) {
        sum_add += (op1[i][j] + op2[i][j]);
    }
    out[i] = sum_add;
}

}
