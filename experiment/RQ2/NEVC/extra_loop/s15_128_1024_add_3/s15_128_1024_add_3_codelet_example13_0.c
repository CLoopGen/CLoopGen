#include <stdio.h>

extern int A[][1024];
extern int B[][1024];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128; i++) {
    int result = 0;
    for (j = 0; j < 1024; j += 8) {
        result += (A[i][j] + B[i][j]);
    }
    out[i] = result;
}

}
