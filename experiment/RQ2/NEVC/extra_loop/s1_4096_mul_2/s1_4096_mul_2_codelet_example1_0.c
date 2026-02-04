#include <stdio.h>

extern int output[4096] __attribute__((aligned(16)));
extern int input1[4096] __attribute__((aligned(16)));
extern int input2[4096] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    output[i] = input1[i] * input2[i];
}

}
