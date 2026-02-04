#include <stdio.h>

extern int result[1024] __attribute__((aligned(16)));
extern int input[1024] __attribute__((aligned(16)));
extern int x;
extern int i;

void loop(){
for (i = 0; i < 1024 - x; i++) {
    result[i] *= input[i + x];
}

}
