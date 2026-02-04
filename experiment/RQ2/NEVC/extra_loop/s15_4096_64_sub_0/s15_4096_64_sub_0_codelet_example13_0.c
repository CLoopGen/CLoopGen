#include <stdio.h>

extern int A[][64];
extern int B[][64];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 4096; i++) {
    int sub = 0;
    for (j = 0; j < 64; j += 8) {
        sub += (A[i][j] - B[i][j]);
    }
    out[i] = sub;
}

}
