#include <stdio.h>

extern int op1[][1024];
extern int op2[][1024];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048; i++) {
    int sum_add = 0;
    for (j = 0; j < 1024; j += 8) {
        sum_add += (op1[i][j] + op2[i][j]);
    }
    out[i] = sum_add;
}

}
