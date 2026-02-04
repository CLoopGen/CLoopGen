#include <stdio.h>

extern int in1[][8192];
extern int in2[][8192];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 64; i++) {
    int res = 0;
    for (j = 0; j < 8192; j += 8) {
        res += (in1[i][j] + in2[i][j]);
    }
    out[i] = res;
}

}
