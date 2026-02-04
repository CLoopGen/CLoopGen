#include <stdio.h>

extern int output1[4096] __attribute__((aligned(16)));
extern int input1[4096] __attribute__((aligned(16)));
extern int input2[4096] __attribute__((aligned(16)));
extern int output2[4096] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 4096 / 4; i++) {
    output1[i] = input1[2 * i + 1] * input2[2 * i + 1] - input1[2 * i] * input2[2 * i];
    output2[i] = input1[2 * i] * input2[2 * i + 1] - input1[2 * i + 1] * input2[2 * i];
}

}
