#include <stdio.h>

extern int A[][512];
extern int B[][512];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    int result = 0;
    for (j = 0; j < 512; j += 8) {
        result += (A[i][j] - B[i][j]);
    }
    out[i] = result;
}

}
