#include <stdio.h>

extern int in1[][256];
extern int in2[][256];
extern int *out;
extern int i;
extern int j;

void loop(){
for (i = 0; i < 4096; i++) {
    int output = 0;
    for (j = 0; j < 256; j += 8) {
        output += (in1[i][j] + in2[i][j]);
    }
    out[i] = output;
}

}
