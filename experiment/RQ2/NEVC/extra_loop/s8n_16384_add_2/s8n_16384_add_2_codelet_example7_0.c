#include <stdio.h>

extern int output[16384] __attribute__((aligned(16)));
extern int input[16384] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 16384 - x; i++) {
    output[i] += input[i + x];
}

}
