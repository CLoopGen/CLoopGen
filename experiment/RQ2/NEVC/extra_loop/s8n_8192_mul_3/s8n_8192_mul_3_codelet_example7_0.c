#include <stdio.h>

extern int result[8192] __attribute__((aligned(16)));
extern int input[8192] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 8192 - x; i++) {
    result[i] *= input[i + x];
}

}
