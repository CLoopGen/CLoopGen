#include <stdio.h>

extern int result[512] __attribute__((aligned(16)));
extern int input[512] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 512 - x; i++) {
    result[i] = input[i + x];
}

}
