#include <stdio.h>

extern int in1[][128];
extern int in2[][128];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 256; i++) {
    int output = 0;
    for (j = 0; j < 128; j += 8) {
        output += (in1[i][j] + in2[i][j]);
    }
    out[i] = output;
}

}
