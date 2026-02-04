#include <stdio.h>

extern int A[][128];
extern int B[][128];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384; i++) {
    int sub = 0;
    for (j = 0; j < 128; j += 8) {
        sub += (A[i][j] - B[i][j]);
    }
    out[i] = sub;
}

}
