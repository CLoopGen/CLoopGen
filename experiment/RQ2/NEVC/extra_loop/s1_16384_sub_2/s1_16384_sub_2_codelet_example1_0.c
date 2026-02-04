#include <stdio.h>

extern int output[16384] __attribute__((aligned(16)));
extern int input1[16384] __attribute__((aligned(16)));
extern int input2[16384] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 16384; i++) {
    output[i] = input1[i] - input2[i];
}

}
