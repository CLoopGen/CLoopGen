#include <stdio.h>

extern int A[][1024];
extern int B[][1024];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    int sub = 0;
    for (j = 0; j < 1024; j += 8) {
        sub += (A[i][j] - B[i][j]);
    }
    out[i] = sub;
}

}
