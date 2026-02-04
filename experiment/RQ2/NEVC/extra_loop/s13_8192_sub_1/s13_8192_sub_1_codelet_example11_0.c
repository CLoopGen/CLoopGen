#include <stdio.h>

extern int out1[8192] __attribute__((aligned(16)));
extern int in1[8192] __attribute__((aligned(16)));
extern int in2[8192] __attribute__((aligned(16)));
extern int out2[8192] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 8192 / 4; i++) {
    out1[i] = in1[2 * i + 1] * in2[2 * i + 1] - in1[2 * i] * in2[2 * i];
    out2[i] = in1[2 * i] * in2[2 * i + 1] - in1[2 * i + 1] * in2[2 * i];
}

}
