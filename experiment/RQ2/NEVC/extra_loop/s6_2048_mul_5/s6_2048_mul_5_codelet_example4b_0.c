#include <stdio.h>

extern int sum[2048] __attribute__((aligned(16)));
extern int in1[2048] __attribute__((aligned(16)));
extern int in2[2048] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 2048 - 4; i++) {
    sum[i] = in1[i + 1] * in2[i + 3];
}

}
