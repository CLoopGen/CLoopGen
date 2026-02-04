#include <stdio.h>

extern int in1[][1024];
extern int in2[][1024];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 8192; i++) {
    int res = 0;
    for (j = 0; j < 1024; j += 8) {
        res += (in1[i][j] - in2[i][j]);
    }
    out[i] = res;
}

}
