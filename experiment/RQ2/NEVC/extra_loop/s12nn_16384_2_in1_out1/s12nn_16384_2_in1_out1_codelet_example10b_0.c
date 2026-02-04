#include <stdio.h>

extern short *restrict in1;
extern short *restrict in2;
extern short *restrict in3;
extern int *restrict out1;
extern int *restrict out2;
extern int *restrict out3;
extern int i;

void loop(){
for (i = 0; i < 16384; i += 2) {
    out1[i] = (int)in1[i];
    out2[i] = (int)in2[i];
    out3[i] = (int)in3[i];
}

}
