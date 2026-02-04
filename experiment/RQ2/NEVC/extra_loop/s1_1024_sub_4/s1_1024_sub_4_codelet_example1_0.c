#include <stdio.h>

extern int result[1024] __attribute__((aligned(16)));
extern int in1[1024] __attribute__((aligned(16)));
extern int in2[1024] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 1024; i++) {
    result[i] = in1[i] - in2[i];
}

}
