#include <stdio.h>

extern int A[][4096];
extern int B[][4096];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64; i++) {
    int result = 0;
    for (j = 0; j < 4096; j += 8) {
        result += (A[i][j] * B[i][j]);
    }
    out[i] = result;
}

}
