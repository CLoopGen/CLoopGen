#include <stdio.h>

extern int A[][2048];
extern int B[][2048];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384; i++) {
    int result = 0;
    for (j = 0; j < 2048; j += 8) {
        result += (A[i][j] - B[i][j]);
    }
    out[i] = result;
}

}
