#include <stdio.h>

extern int out[64] __attribute__((aligned(16)));
extern int in1[64] __attribute__((aligned(16)));
extern int in2[64] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 64; i++) {
    out[i] = in1[i] + in2[i];
}

}
