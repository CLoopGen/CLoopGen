#include <stdio.h>

extern int in1[][64];
extern int in2[][64];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 2048; i++) {
    int output = 0;
    for (j = 0; j < 64; j += 8) {
        output += (in1[i][j] - in2[i][j]);
    }
    out[i] = output;
}

}
