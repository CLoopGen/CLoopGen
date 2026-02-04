#include <stdio.h>

extern int result[1024] __attribute__((aligned(16)));
extern int in1[1024] __attribute__((aligned(16)));
extern int in2[1024] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 1024 - 4; i += 2) {
    result[i] = in1[i + 1] * in2[i + 3];
    result[i + 1] = in1[i] * in2[i + 2];
}

}
