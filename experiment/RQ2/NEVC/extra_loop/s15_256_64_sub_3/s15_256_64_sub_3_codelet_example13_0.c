#include <stdio.h>

extern int A[][64];
extern int B[][64];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    int result = 0;
    for (j = 0; j < 64; j += 8) {
        result += (A[i][j] - B[i][j]);
    }
    out[i] = result;
}

}
