#include <stdio.h>

extern int out[2048] __attribute__((aligned(16)));
extern int in1[2048] __attribute__((aligned(16)));
extern int in2[2048] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 2048; i++) {
    out[i] = in1[i] - in2[i];
}

}
