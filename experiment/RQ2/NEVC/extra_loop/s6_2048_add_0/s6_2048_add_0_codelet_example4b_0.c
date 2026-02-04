#include <stdio.h>

extern int a[2048] __attribute__((aligned(16)));
extern int b[2048] __attribute__((aligned(16)));
extern int c[2048] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 2048 - 4; i++) {
    a[i] = b[i + 1] + c[i + 3];
}

}
