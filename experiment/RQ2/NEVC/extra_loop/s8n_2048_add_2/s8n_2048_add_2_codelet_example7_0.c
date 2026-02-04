#include <stdio.h>

extern int output[2048] __attribute__((aligned(16)));
extern int input[2048] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 2048 - x; i++) {
    output[i] += input[i + x];
}

}
