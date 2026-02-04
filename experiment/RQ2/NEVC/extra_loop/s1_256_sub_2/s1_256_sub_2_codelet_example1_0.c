#include <stdio.h>

extern int output[256] __attribute__((aligned(16)));
extern int input1[256] __attribute__((aligned(16)));
extern int input2[256] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 256; i++) {
    output[i] = input1[i] - input2[i];
}

}
