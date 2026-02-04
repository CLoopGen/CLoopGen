#include <stdio.h>

extern int out[64] __attribute__((aligned(16)));
extern int in1[64] __attribute__((aligned(16)));
extern int in2[64] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 64 - 4; i += 2) {
    out[i] = in1[i + 1] - in2[i + 3];
    out[i + 1] = in1[i] - in2[i + 2];
}

}
