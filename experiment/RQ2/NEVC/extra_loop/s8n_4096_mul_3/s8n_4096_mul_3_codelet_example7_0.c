#include <stdio.h>

extern int result[4096] __attribute__((aligned(16)));
extern int input[4096] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 4096 - x; i++) {
    result[i] *= input[i + x];
}

}
