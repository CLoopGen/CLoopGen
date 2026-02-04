#include <stdio.h>

extern int sum[1024] __attribute__((aligned(16)));
extern int in1[1024] __attribute__((aligned(16)));
extern int in2[1024] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 1024 - 4; i++) {
    sum[i] = in1[i + 1] + in2[i + 3];
}

}
