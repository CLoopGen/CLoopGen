#include <stdio.h>

extern int output[1024] __attribute__((aligned(16)));
extern int input1[1024] __attribute__((aligned(16)));
extern int input2[1024] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    output[i] = input1[i] - input2[i];
}

}
