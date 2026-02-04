#include <stdio.h>

extern int result[64] __attribute__((aligned(16)));
extern int in1[64] __attribute__((aligned(16)));
extern int in2[64] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 64 - 4; i++) {
    result[i] = in1[i + 1] + in2[i + 3];
}

}
