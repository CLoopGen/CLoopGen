#include <stdio.h>

extern int sum_mul1[256] __attribute__((aligned(16)));
extern int in1[256] __attribute__((aligned(16)));
extern int in2[256] __attribute__((aligned(16)));
extern int sum_mul2[256] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 256 / 4; i++) {
    sum_mul1[i] = in1[2 * i + 1] * in2[2 * i + 1] - in1[2 * i] * in2[2 * i];
    sum_mul2[i] = in1[2 * i] * in2[2 * i + 1] * in1[2 * i + 1] * in2[2 * i];
}

}
