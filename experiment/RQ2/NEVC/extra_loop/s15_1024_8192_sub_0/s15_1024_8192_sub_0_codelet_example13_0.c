#include <stdio.h>

extern int A[][8192];
extern int B[][8192];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    int sub = 0;
    for (j = 0; j < 8192; j += 8) {
        sub += (A[i][j] - B[i][j]);
    }
    out[i] = sub;
}

}
