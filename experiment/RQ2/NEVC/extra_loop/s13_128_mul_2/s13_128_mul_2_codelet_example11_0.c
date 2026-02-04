#include <stdio.h>

extern int output1[128] __attribute__((aligned(16)));
extern int input1[128] __attribute__((aligned(16)));
extern int input2[128] __attribute__((aligned(16)));
extern int output2[128] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 128 / 4; i++) {
    output1[i] = input1[2 * i + 1] * input2[2 * i + 1] - input1[2 * i] * input2[2 * i];
    output2[i] = input1[2 * i] * input2[2 * i + 1] * input1[2 * i + 1] * input2[2 * i];
}

}
