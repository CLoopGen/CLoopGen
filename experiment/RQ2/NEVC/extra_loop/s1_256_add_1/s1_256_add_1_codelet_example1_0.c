#include <stdio.h>

extern int out[256] __attribute__((aligned(16)));
extern int in1[256] __attribute__((aligned(16)));
extern int in2[256] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 256; i++) {
    out[i] = in1[i] + in2[i];
}

}
