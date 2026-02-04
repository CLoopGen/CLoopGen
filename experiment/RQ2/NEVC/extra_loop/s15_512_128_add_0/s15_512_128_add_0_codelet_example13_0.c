#include <stdio.h>

extern int A[][128];
extern int B[][128];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 512; i++) {
    int add = 0;
    for (j = 0; j < 128; j += 8) {
        add += (A[i][j] + B[i][j]);
    }
    out[i] = add;
}

}
