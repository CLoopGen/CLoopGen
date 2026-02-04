#include <stdio.h>

extern int result[256] __attribute__((aligned(16)));
extern int input[256] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 256 - x; i++) {
    result[i] += input[i + x];
}

}
