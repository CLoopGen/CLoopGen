#include <stdio.h>

extern int A[][256];
extern int B[][256];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 16384; i++) {
    int add = 0;
    for (j = 0; j < 256; j += 8) {
        add += (A[i][j] + B[i][j]);
    }
    out[i] = add;
}

}
