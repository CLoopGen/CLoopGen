#include <stdio.h>

extern int A[][4096];
extern int B[][4096];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    int sub = 0;
    for (j = 0; j < 4096; j += 8) {
        sub += (A[i][j] - B[i][j]);
    }
    out[i] = sub;
}

}
