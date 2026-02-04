#include <stdio.h>

extern int result1[128] __attribute__((aligned(16)));
extern int in1[128] __attribute__((aligned(16)));
extern int in2[128] __attribute__((aligned(16)));
extern int result2[128] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 128 / 4; i++) {
    result1[i] = in1[2 * i + 1] * in2[2 * i + 1] - in1[2 * i] * in2[2 * i];
    result2[i] = in1[2 * i] * in2[2 * i + 1] + in1[2 * i + 1] * in2[2 * i];
}

}
