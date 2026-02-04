#include <stdio.h>

extern int output[8192] __attribute__((aligned(16)));
extern int input1[8192] __attribute__((aligned(16)));
extern int input2[8192] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 8192; i++) {
    output[i] = input1[i] - input2[i];
}

}
