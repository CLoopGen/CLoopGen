#include <stdio.h>

extern int result[128] __attribute__((aligned(16)));
extern int input[128] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 128 - x; i++) {
    result[i] *= input[i + x];
}

}
