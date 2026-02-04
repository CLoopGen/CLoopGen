#include <stdio.h>

extern int in1[][2048];
extern int in2[][2048];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 128; i++) {
    int output = 0;
    for (j = 0; j < 2048; j += 8) {
        output += (in1[i][j] + in2[i][j]);
    }
    out[i] = output;
}

}
