#include <stdio.h>

extern int output[128] __attribute__((aligned(16)));
extern int input1[128] __attribute__((aligned(16)));
extern int input2[128] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 128; i++) {
    output[i] = input1[i] * input2[i];
}

}
