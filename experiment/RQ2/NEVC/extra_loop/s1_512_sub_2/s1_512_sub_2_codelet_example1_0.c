#include <stdio.h>

extern int output[512] __attribute__((aligned(16)));
extern int input1[512] __attribute__((aligned(16)));
extern int input2[512] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 512; i++) {
    output[i] = input1[i] - input2[i];
}

}
