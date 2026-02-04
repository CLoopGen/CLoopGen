#include <stdio.h>

extern int in1[][512];
extern int in2[][512];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 1024; i++) {
    int output = 0;
    for (j = 0; j < 512; j += 8) {
        output += (in1[i][j] + in2[i][j]);
    }
    out[i] = output;
}

}
