#include <stdio.h>

extern int output[512] __attribute__((aligned(16)));
extern int input1[512] __attribute__((aligned(16)));
extern int input2[512] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 512 - 4; i++) {
    output[i] = input1[i + 1] + input2[i + 3];
}

}
