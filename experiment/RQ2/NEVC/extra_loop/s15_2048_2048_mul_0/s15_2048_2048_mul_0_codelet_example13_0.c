#include <stdio.h>

extern int A[][2048];
extern int B[][2048];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048; i++) {
    int mul = 0;
    for (j = 0; j < 2048; j += 8) {
        mul += (A[i][j] * B[i][j]);
    }
    out[i] = mul;
}

}
