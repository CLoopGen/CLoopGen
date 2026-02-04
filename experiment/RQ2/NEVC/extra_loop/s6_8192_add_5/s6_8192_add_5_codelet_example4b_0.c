#include <stdio.h>

extern int sum[8192] __attribute__((aligned(16)));
extern int in1[8192] __attribute__((aligned(16)));
extern int in2[8192] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 8192 - 4; i++) {
    sum[i] = in1[i + 1] + in2[i + 3];
}

}
