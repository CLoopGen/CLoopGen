#include <stdio.h>

extern int result[4096] __attribute__((aligned(16)));
extern int in1[4096] __attribute__((aligned(16)));
extern int in2[4096] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 4096; i++) {
    result[i] = in1[i] + in2[i];
}

}
