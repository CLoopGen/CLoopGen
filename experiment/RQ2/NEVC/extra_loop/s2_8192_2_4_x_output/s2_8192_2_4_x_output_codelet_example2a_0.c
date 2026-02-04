#include <stdio.h>

extern int output[8192] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 8192 - 3; i += 4) {
    output[i] = x;
    output[i + 1] = -x;
    output[i + 2] = x;
    output[i + 3] = -x;
}

}
