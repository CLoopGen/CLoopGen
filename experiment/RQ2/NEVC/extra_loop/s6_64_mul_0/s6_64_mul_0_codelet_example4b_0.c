#include <stdio.h>

extern int a[64] __attribute__((aligned(16)));
extern int b[64] __attribute__((aligned(16)));
extern int c[64] __attribute__((aligned(16)));
extern int i;

void loop(){
for (i = 0; i < 64 - 4; i++) {
    a[i] = b[i + 1] * c[i + 3];
}

}
