#include <stdio.h>

extern int result1[64] __attribute__((aligned(16)));
extern int in1[64] __attribute__((aligned(16)));
extern int in2[64] __attribute__((aligned(16)));
extern int result2[64] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 64 / 4; i++) {
    result1[i] = in1[2 * i + 1] * in2[2 * i + 1] - in1[2 * i] * in2[2 * i];
    result2[i] = in1[2 * i] * in2[2 * i + 1] * in1[2 * i + 1] * in2[2 * i];
}

}
