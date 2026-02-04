#include <stdio.h>

extern int op1[][64];
extern int op2[][64];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    int sum_sub = 0;
    for (j = 0; j < 64; j += 8) {
        sum_sub += (op1[i][j] - op2[i][j]);
    }
    out[i] = sum_sub;
}

}
