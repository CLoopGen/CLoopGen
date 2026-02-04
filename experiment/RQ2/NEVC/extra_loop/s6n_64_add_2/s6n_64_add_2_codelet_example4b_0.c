#include <stdio.h>

extern int output[64] __attribute__((aligned(16)));
extern int input1[64] __attribute__((aligned(16)));
extern int input2[64] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 64 - 4; i += 2) {
    output[i] = input1[i + 1] + input2[i + 3];
    output[i + 1] = input1[i] + input2[i + 2];
}

}
