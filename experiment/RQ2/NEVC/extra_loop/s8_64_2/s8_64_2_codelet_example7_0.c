#include <stdio.h>

extern int output[64] __attribute__((aligned(16)));
extern int input[64] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 64 - x; i++) {
    output[i] = input[i + x];
}

}
