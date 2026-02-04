#include <stdio.h>

extern int result[128] __attribute__((aligned(16)));
extern int in1[128] __attribute__((aligned(16)));
extern int in2[128] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 128; i++) {
    result[i] = in1[i] - in2[i];
}

}
