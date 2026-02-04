#include <stdio.h>

extern int A[][4096];
extern int B[][4096];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    int add = 0;
    for (j = 0; j < 4096; j += 8) {
        add += (A[i][j] + B[i][j]);
    }
    out[i] = add;
}

}
