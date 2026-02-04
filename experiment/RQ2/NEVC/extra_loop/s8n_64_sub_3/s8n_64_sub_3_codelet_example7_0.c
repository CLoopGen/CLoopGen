#include <stdio.h>

extern int result[64] __attribute__((aligned(16)));
extern int input[64] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 64 - x; i++) {
    result[i] -= input[i + x];
}

}
