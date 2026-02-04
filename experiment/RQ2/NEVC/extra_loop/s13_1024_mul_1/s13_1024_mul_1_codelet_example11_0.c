#include <stdio.h>

extern int out1[1024] __attribute__((aligned(16)));
extern int in1[1024] __attribute__((aligned(16)));
extern int in2[1024] __attribute__((aligned(16)));
extern int out2[1024] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 1024 / 4; i++) {
    out1[i] = in1[2 * i + 1] * in2[2 * i + 1] - in1[2 * i] * in2[2 * i];
    out2[i] = in1[2 * i] * in2[2 * i + 1] * in1[2 * i + 1] * in2[2 * i];
}

}
