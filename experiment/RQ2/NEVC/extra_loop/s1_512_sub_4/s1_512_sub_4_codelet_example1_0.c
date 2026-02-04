#include <stdio.h>

extern int result[512] __attribute__((aligned(16)));
extern int in1[512] __attribute__((aligned(16)));
extern int in2[512] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 512; i++) {
    result[i] = in1[i] - in2[i];
}

}
