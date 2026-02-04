#include <stdio.h>

extern int output[128] __attribute__((aligned(16)));
extern int input[128] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 128 - x; i++) {
    output[i] *= input[i + x];
}

}
